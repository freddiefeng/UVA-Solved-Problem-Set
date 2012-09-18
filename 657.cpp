#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 50

struct Vertex
{
	char pixel;
	int CGID;
	bool recognized;
};

Vertex picture[MAX][MAX];

vector<int> results;

int width, height;

void bfs_dots(const int & row, const int & column, const int & index)
{
	if(picture[row][column].pixel == 'X')
	{
		picture[row][column].recognized = true;
	}

	if(row + 1 < height &&
		picture[row + 1][column].recognized == false &&
		picture[row + 1][column].pixel == 'X')
	{
		bfs_dots(row + 1, column, index);
	}

	if(row - 1 >= 0 && 
		picture[row - 1][column].recognized == false &&
		picture[row - 1][column].pixel == 'X')
	{
		bfs_dots(row - 1, column, index);
	}

	if(column + 1 < width && 
		picture[row][column + 1].recognized == false &&
		picture[row][column + 1].pixel == 'X')
	{
		bfs_dots(row, column + 1, index);
	}

	if(column - 1 >= 0 &&
		picture[row][column - 1].recognized == false &&
	 	picture[row][column - 1].pixel == 'X')
	{
		bfs_dots(row, column - 1, index);
	}
}

void bfs(const int & row, const int & column, const int & index)
{
	// cout << row << " " << column << endl;
	picture[row][column].CGID = index;
	if(picture[row][column].pixel == 'X' && picture[row][column].recognized == false)
	{
		results[index] += 1;
		bfs_dots(row, column, index);
	}

	if(row + 1 < height && 
			picture[row + 1][column].CGID == -1 && picture[row + 1][column].pixel != '.'
		)
	{
		bfs(row + 1, column, index);
	}

	if(row - 1 >= 0 && 
			picture[row - 1][column].CGID == -1 && picture[row - 1][column].pixel != '.'
		)
	{
		bfs(row - 1, column, index);
	}

	if(column + 1 < width && 
		picture[row][column + 1].CGID == -1 && picture[row][column + 1].pixel != '.'
		)
	{
		bfs(row, column + 1, index);
	}

	if(column - 1 >= 0 &&
		picture[row][column - 1].CGID == -1 && picture[row][column - 1].pixel != '.'
		)
	{
		bfs(row, column - 1, index);
	}

	return;
}

int main()
{
	int counter = 0;

	while(true)
	{
		cin >> width >> height;

		if(width == 0 && height == 0)
		{
			break;
		}

		results.clear();

		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				cin >> picture[i][j].pixel;
				picture[i][j].CGID = -1;
				picture[i][j].recognized = false;
			}
		}

		int index = 0;

		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				if(picture[i][j].CGID == -1 && picture[i][j].pixel != '.')
				{
					index = results.size();
					results.push_back(0);
					bfs(i, j, index);
				}
			}
		}

		cout << "Throw " << ++counter << endl;
		if(results.size() > 0)
		{
			sort(results.begin(), results.end());
			int i = 0;
			for(; i < results.size() - 1; i++)
			{
				cout << results[i] << " ";
			}
			cout << results[i] << endl << endl;
		}
		else
		{
			cout << 0 << endl << endl;
		}
	}
}