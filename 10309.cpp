#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int steps[1024];

struct grid
{
	bool states[10][10];
};

void toggle(grid& g, int row, int col)
{

	g.states[row][col] = !g.states[row][col];

	if(row > 0)
	{
		g.states[row - 1][col] = !g.states[row - 1][col];
	}

	if(col > 0)
	{
		g.states[row][col - 1] = !g.states[row][col - 1];
	}

	if(row + 1 < 10)
	{
		g.states[row + 1][col] = !g.states[row + 1][col];
	}

	if(col + 1 < 10)
	{
		g.states[row][col + 1] = !g.states[row][col + 1];
	}
}

int search(grid g, int row, int nStep)
{
	if(nStep > 100)
		return -1;

	for(int row = 1; row < 10; row++)
	{
		for(int i = 0; i < 10; i++)
		{
			if(g.states[row - 1][i] == true)
			{
				toggle(g, row, i);
				nStep++;
			}
		}
	}

	for(int i = 0; i < 10; i++)
	{
		if(g.states[9][i] == true)
		{
			return -1;
		}
	}

	return nStep;

}

void solve(grid g, string name)
{
	grid newgrid;
	
	for(int i = 0; i < 1024; i++)
	{
		steps[i] = -1;
	}

	int nStep;
	int result;

	for(int i = 0; i < 1024; i++)
	{
		newgrid = g;
		nStep = 0;
		bitset<10> bs(i);

		for(int j = 0; j < 10; j++)
		{
			if(bs.test(j))
			{
				toggle(newgrid, 0, j);
				nStep++;
			}
		}

		result = search(newgrid, 1, nStep);

		if(result != -1)
		{
			steps[i] = result;
		}
	}

	int min = 101;

	for(int i = 0; i < 1024; i++)
	{
		if(steps[i] != -1 && steps[i] < min)
		{
			min = steps[i];
		}
	}

	cout << name << " ";
	if(min != 101)
	{
		cout << min << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

int main()
{

	string name;

	while(true)
	{
		cin >> name;

		if(name == "end")
			break;

		grid g;

		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
			{
				char input;
				cin >> input;
				g.states[i][j] = (input == '#' ? false : true);
			}

		solve(g, name);
	}
}