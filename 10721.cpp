#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long states[52][52];
int n, k, m;

long long computeResult(int numUnits, int numBars)
{
	if(states[numUnits][numBars] != 0)
	{
		return states[numUnits][numBars];
	}
	else
	{
		if(numBars == 1)
		{
			return states[numUnits][numBars];
		}
		else
		{
			for(int i = max(numUnits - m, 1); i < numUnits; i++)
			{
				if(numBars -1 <= i)
				{
					states[numUnits][numBars] += computeResult(i, numBars - 1);
				}
			}
			return states[numUnits][numBars];
		}
	}
	return 0;
}

int main()
{
	while(true)
	{
		cin >> n;
		if(cin.fail())
			break;

		cin >> k >> m;

		memset(states, 0, sizeof(states));

		for(int i = 1; i <= m; i++)
		{
			states[i][1] = 1;
		}

		long long result = computeResult(n, k);

		cout << result << endl;
	}
}