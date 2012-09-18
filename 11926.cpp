#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1000001
#define MAX_TASKS 100

bool slot[MAX];
int start[MAX_TASKS], end[MAX_TASKS];
int rstart[MAX_TASKS], rend[MAX_TASKS], intervals[MAX_TASKS];

int check(int n, int m)
{
	memset(slot, 0, MAX);
	for(int i = 0; i < n; i++)
	{
		for(int j = start[i]; j < end[i]; j++)
		{
			if(slot[j] != 0)
			{
				return 0;
			}
			slot[j] = 1;
		}
	}

	int interval, rStatTime, step;
	for(int i = 0; i < m; i++)
	{
		interval = intervals[i];
		rStatTime = rstart[i];
		step = rend[i] - rstart[i]; 
		while(rStatTime < MAX)
		{
			for(int j = rStatTime; j < rStatTime + step && j < MAX; j++)
			{
				if(slot[j] != 0)
				{
					return 0;
				}
				slot[j] = 1;
			}

			rStatTime += interval;
		}
	}

	return 1;
}

int main()
{
	int n, m;

	while(true)
	{
		cin >> n >> m;
		if(n == 0 && m == 0)
		{
			break;
		}

		for(int i = 0; i < n; i++)
		{
			cin >> start[i] >> end[i];
		}

		for(int i = 0; i < m; i++)
		{
			cin >> rstart[i] >> rend[i] >> intervals[i];
		}

		int result = check(n, m);

		cout << (result == 0 ? "CONFLICT" : "NO CONFLICT") << endl;
	}
}