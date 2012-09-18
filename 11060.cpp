#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int inDegree[100];
string beverages[100];

int orders[100][100];

int main()
{
	int N = 0, M = 0;
	int counter = 0;

	string left, right;

	while(true)
	{
		cin >> N;
		if(cin.fail())
		{
			break;
		}

		map<string, int> lookupTable;
		vector<int> result;
		queue<int> bfs_queue;

		for(int i = 0; i < N; i++)
		{
			inDegree[i] = 0;
			for(int j = 0; j < N; j++)
			{
				orders[i][j] = 0;
			}

			cin >> beverages[i];
			lookupTable.insert( pair<string, int>(beverages[i], i));
		}

		cin >> M;

		for(int i = 0; i < M; i++)
		{
			cin >> left;
			cin >> right;
			if(orders[lookupTable[left]][lookupTable[right]] != 1)
			{
				orders[lookupTable[left]][lookupTable[right]] = 1;
				inDegree[ lookupTable[right] ]++;
			}
		}

		for(int i = 0; i < N; i++)
		{
			if(inDegree[i] == 0)
			{
				bfs_queue.push(i);
				break;
			}
		}

		int u, v;
		while(!bfs_queue.empty())
		{
			u = bfs_queue.front();
			bfs_queue.pop();

			result.push_back(u);
			inDegree[u] = -1;

			for(int i = 0; i < N; i++)
			{
				if(orders[u][i] == 1)
				{
					inDegree[i]--;
				}
			}

			for(int i = 0; i < N; i++)
			{
				if(inDegree[i] == 0)
				{
					bfs_queue.push(i);
					break;
				}
			}
		}

		cout << "Case #" << ++counter << ": Dilbert should drink beverages in this order: ";
		
		for(int i = 0; i < result.size() - 1; i++)
		{
			cout << beverages[ result[i] ] << " ";
		}

		cout << beverages[ result.back() ] << "." << endl;

		cout << endl;
	}
}