#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pset;

struct Edge {
	int weight;
	int from;
	int to;
};

int findSet(int index)
{
	if(pset[index] == index)
	{
		return index;
	}
	else
	{
		pset[index] = findSet(pset[index]);
		return  pset[index];
	}
}

bool bSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

void unionSet(int left, int right)
{
	pset[findSet(left)] = findSet(right);
}

int compare(const void* left, const void* right)
{
	return (((Edge *)left)->weight - ((Edge *)right)->weight);
}

int main()
{
	int m, n;
	Edge EdgeList[200001];

	while(true)
	{
		cin >> m >> n;

		if(m == 0 && n == 0)
			break;

		int left, right, weight, sum = 0;;
		// cout << "passed" << endl;

		for(int i = 0; i < n; i++)
		{
			cin >> left >> right >> weight;
			EdgeList[i].weight = weight;
			EdgeList[i].from = left;
			EdgeList[i].to = right;
			sum += weight;
		}


		qsort(EdgeList, n, sizeof(Edge), &compare);
		pset.assign(n, 0);

		int mst = 0;
		for(int i = 0; i < m; i++)
		{
			pset[i] = i;
		}

		for(int i = 0; i < n; i++)
		{
			Edge edge = EdgeList[i];
			if(!bSameSet(edge.from, edge.to))
			{
				mst += edge.weight;
				unionSet(edge.from, edge.to);
			}
		}

		cout << sum - mst << endl;
	}
}
