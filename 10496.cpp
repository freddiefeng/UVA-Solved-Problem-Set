#include <iostream>
#include <cmath>
#include <cstring>

int nCases;
int xSize, ySize, xStart, yStart, nBeepers, N;
int beepers[11][2];
int costs[11][2048];

int distance(int left, int right)
{
	return std::abs(beepers[left][0] - beepers[right][0]) + std::abs(beepers[left][1] - beepers[right][1]);
}

int tcp(int cur, int bitmask)
{
	if(costs[cur][bitmask] != 0)
	{
		return costs[cur][bitmask];
	}
	else
	{
		int min = 4000;
		int tmp;
		int tmpIndex;
		
		for(int i = 0; i < N; i++)
		{
			if(cur != i && (bitmask & (1 << i)) == 0)
			{
				tmp = distance(cur, i) + tcp(i, bitmask | (1 << i));
				if(tmp < min)
				{
					tmpIndex = i;
					min = tmp;
				}
			}
		}

		costs[cur][bitmask] = min < 4000 ? min : 0;
		return costs[cur][bitmask];
	}
}

int main()
{
	std::cin >> nCases;

	while(nCases--)
	{
		std::cin >> xSize >> ySize >> xStart >> yStart >> nBeepers;

		beepers[0][0] = xStart;
		beepers[0][1] = yStart;

		memset(costs, 0, sizeof(costs));

		N = nBeepers + 1;

		for(int i = 1; i < N; i++)
		{
			std::cin >> beepers[i][0] >> beepers[i][1];

			costs[i][(1 << N) - 1] = distance(0, i);
		}

		int shortestPath = tcp(0, 1);

		std::cout << "The shortest path has length " << shortestPath << std::endl;
	}
}