#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

#define MAX_NUM_STATION 51+2

struct station {
	double distance;
	double unit_price;
};

station stations[MAX_NUM_STATION];

double min_cost = numeric_limits<double>::max();

double capacity, unit_consumption, base_cost;
int num_stations;

bool bStop(const int & start, const int & end)
{
	double distance = stations[end].distance - stations[start].distance;

	double gas_left = capacity - distance / unit_consumption;

	if(gas_left < 0)
	{
		return false;
	}

	if(gas_left <= capacity / 2.0)
	{
		return true;
	}

	if(end == num_stations - 1)
	{
		return true;
	}

	double next_distance = stations[end + 1].distance - stations[start].distance;

	if(capacity - next_distance * unit_consumption < 0)
	{
		return true;
	}

	return false;
}

void backtrack(int index, double cost, double gas)
{
	if(index == num_stations - 1)
	{
		if(min_cost > cost)
		{
			min_cost = cost;
		}
	}

	double new_cost = cost + stations[index].unit_price * (capacity - gas) + 
					(index > 0 && index < MAX_NUM_STATION ? 2.0 : 0.0);
	double new_gas;

	for(int i = index + 1; i < num_stations; i++)
	{
		if(bStop(index, i))
		{
			new_gas = capacity - (stations[i].distance - stations[index].distance) / unit_consumption;
			backtrack(i, new_cost, new_gas);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	double distance;

	int nCases = 0;

	while(true)
	{
		cin >> distance;

		if(distance == -1) break;

		cin >> capacity >> unit_consumption >> base_cost >> num_stations;

		min_cost = numeric_limits<double>::max();

		num_stations += 2;

		stations[0].distance = 0;
		stations[0].unit_price = 0;
		stations[num_stations - 1].distance = distance;
		stations[num_stations - 1].unit_price = 0;

		for(int i = 1; i < num_stations - 1; i++)
		{
			cin >> stations[i].distance;
			cin >> stations[i].unit_price;
			stations[i].unit_price /= 100.0;
		}

		backtrack(0, base_cost, capacity);

		cout << "Data Set #" << ++nCases << endl;
		cout.setf(ios::fixed);
		cout << "minimum cost = $" << setprecision(2) << min_cost << endl;
	}
}