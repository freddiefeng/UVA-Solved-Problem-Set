#include <iostream>

using namespace std;

int carWeights[2001];
int LIS[2001];
int LDS[2001];

int main()
{
	int nCases;
	int nCars;
	cin >> nCases;

	while(nCases--)
	{
		cin >> nCars;
		for(int i = nCars - 1; i >= 0; i--)
		{
			cin >> carWeights[i];
		}

		LIS[0] = 1;
		LDS[0] = 1;

		int j;
		for(int i = 1; i < nCars; i++)
		{
			LIS[i] = 1;
			LDS[i] = 1;
			j = i - 1;
			while(j >= 0)
			{
				if(carWeights[j] < carWeights[i] && LIS[j] >= LIS[i])
				{
					LIS[i] = LIS[j] + 1;
				}

				if(carWeights[j] > carWeights[i] && LDS[j] >= LDS[i])
				{
					LDS[i] = LDS[j] + 1;
				}

				j--;
			}
		}

		int max = 0;

		for(int i = 0; i < nCars; i++)
		{
			if(LIS[i] + LDS[i] - 1 > max)
			{
				max = LIS[i] + LDS[i] - 1;
			}
		}

		cout << max << endl;
	}
}