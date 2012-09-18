#include <iostream>
#include <queue>
#include <map>

using namespace std;

int adjacentMatrix[200][200];

int colors[200];

int main()
{
	int nCases, v, e;
	int left, right;

	cin >> nCases;

	while(nCases--)
	{
		cin >> v >> e;
		queue<int> bfs_queue;

		for(int i = 0; i < v; i++)
		{
			colors[i] = -1;	
			for(int j = 0; j < v; j++)
				adjacentMatrix[i][j] = 0;
		}

		for(int i = 0; i < e; i++)
		{
			cin >> left >> right;

			adjacentMatrix[left][right] = 1;
			adjacentMatrix[right][left] = 1;
		}

		int vertex;
		bool bBipartite = true;
		int white = 0, black = 0, sum = 0, temp = 0;
		for(int i = 0; i < v; i++)
		{
			if(colors[i] < 0)
			{
				white = 0;
				black = 0;

				// cout << "start: " << i << endl;

				bfs_queue.push(i);
				colors[i] = 0;
				white++;

				while(!bfs_queue.empty())
				{
					vertex = bfs_queue.front();
					// cout << vertex << endl;
					bfs_queue.pop();
					for(int j = 0; j < v; j++)
					{
						if(adjacentMatrix[vertex][j] == 1)
						{
							if(colors[j] == -1)
							{
								colors[j] = 1 - colors[vertex];
								if(colors[j] == 0)
								{
									white++;
								}
								else
								{
									black++;
								}
								bfs_queue.push(j);
							}
							else if(colors[vertex] == colors[j])
							{
								bBipartite = false;
								break;
							}
						}
					}

					if(!bBipartite)
					{
						break;
					}
				}

				temp = min(white, black);
				sum += (temp == 0 ? 1 : temp); 
			}

			if(!bBipartite)
			{
				break;
			}
		}

		if(bBipartite)
		{
			cout << sum << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
}