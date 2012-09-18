#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

#define MAX 1000000000

using namespace std;

struct edge
{
	int cost;
	int city;
	int fuel;
	bool operator < (const edge& e) const
	{
		return cost > e.cost;
	}
};

int prices[1001];

int main()
{
	int nCities, nRoads;
	cin >> nCities >> nRoads;

	for(int i = 0; i < nCities; i++)
	{
		cin >> prices[i];
	}

	vector<pair<int, int> > AdjList[1001];
	int u, v, n;

	for(int i = 0; i < nRoads; i++)
	{
		cin >> u >> v >> n;
		AdjList[u].push_back(make_pair(v, n));
		AdjList[v].push_back(make_pair(u, n));
	}

	int nQueries, s, e, c;

	cin >> nQueries;
	int states[1001][101];

	edge newedge, frontedge;
	while(nQueries--)
	{
		int answer = MAX;
		cin >> c >> s >> e;
		priority_queue<edge> pq;

		for(int i = 0 ; i < nCities; i++)
			for(int j = 0; j <= c; j++)
				states[i][j] = MAX;


		states[s][0] = 0;
		newedge = (edge){0, s, 0};
		pq.push(newedge);

		int cost, city, fuel;
		while(!pq.empty())
		{
			frontedge = pq.top();
			pq.pop();

			cost = frontedge.cost;
			city = frontedge.city;
			fuel = frontedge.fuel;

			if(city == e)
			{
				answer = cost;
				break;
			}

			if(cost == states[city][fuel])
			{
				if(fuel < c && cost + prices[city] < states[city][fuel + 1])
				{
					states[city][fuel + 1] = cost + prices[city];
					newedge = (edge){cost + prices[city], city, fuel + 1};
					pq.push(newedge);
				}

				for(int i = 0; i < AdjList[city].size(); i++)
				{
					pair<int, int> dis = AdjList[city][i];


					if(fuel >= dis.second && cost < states[dis.first][fuel - dis.second])
					{
						states[dis.first][fuel - dis.second] = cost;
						newedge = (edge){cost, dis.first, fuel - dis.second};
						pq.push(newedge);
					}
				}
				
			}
		}

		if(answer == MAX)
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout << answer << endl;
		}
	}
}