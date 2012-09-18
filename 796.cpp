#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dfsNumberCounter;
int nCLinks;

void findBridges(int vertex, vector<set<int> > & result, vector<set<int> > & adjacentVertices, 
	int* dfs_num, int* dfs_low, int* dfs_parent)
{
	int adjacentID;
	dfs_num[vertex] = dfsNumberCounter;
	dfs_low[vertex] = dfsNumberCounter;
	dfsNumberCounter++;

	for(set<int>::iterator it = adjacentVertices[vertex].begin(); it != adjacentVertices[vertex].end();
		it++)
	{
		adjacentID = *it;
		if(dfs_num[adjacentID] == 0)
		{
			dfs_parent[adjacentID] = vertex;
			findBridges(adjacentID, result, adjacentVertices, dfs_num, dfs_low, dfs_parent);

			if(dfs_low[adjacentID] > dfs_num[vertex])
			{
				if(adjacentID > vertex)
				{
					result[vertex].insert(adjacentID);
				}
				else
				{
					result[adjacentID].insert(vertex);
				}
				nCLinks++;
			}

			dfs_low[vertex] = min(dfs_low[vertex], dfs_low[adjacentID]);
		}
		else if(adjacentID != dfs_parent[vertex])
		{
			dfs_low[vertex] = min(dfs_low[vertex], dfs_num[adjacentID]);
		}
	}
}

int main()
{
	int nServers;
	int vertexID;
	int nAdjacent;
	char temp;
	int adjacentID;

	while(true)
	{
		cin >> nServers;
		if(cin.fail())
		{
			break;
		}

		nCLinks = 0;
		vector<set<int> > adjacentVertices(nServers);
		vector<set<int> > result(nServers);

		int dfs_num[nServers];
		int dfs_low[nServers];
		int dfs_parent[nServers];

		vertexID = 0;
		nAdjacent = 0;
		dfsNumberCounter = 0;

		for(int i = 0; i < nServers; i++)
		{
			dfs_num[i] = 0;
			dfs_low[i] = 0;
			dfs_parent[i] = 0;

			cin >> vertexID >> temp >> nAdjacent >> temp;

			for(int j = 0; j < nAdjacent; j++)
			{
				cin >> adjacentID;
				adjacentVertices[vertexID].insert(adjacentID);
				adjacentVertices[adjacentID].insert(vertexID);
			}
		}

		for(int i = 0; i < nServers; i++)
		{
			if(dfs_num[i] == 0)
			{
				findBridges(i, result, adjacentVertices, dfs_num, dfs_low, dfs_parent);
			}
		}

		cout << nCLinks << " critical links" << endl;
		for(int i = 0; i < nServers; i++)
		{
			for(set<int>::iterator it = result[i].begin(); it != result[i].end();
				it++)
			{
				cout << i << " - " << *it << endl;
			}
		}
		cout << endl;
	}
}