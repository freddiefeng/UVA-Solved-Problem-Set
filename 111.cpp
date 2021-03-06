#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>
#define MAX 20

using namespace std;

int m[MAX][MAX];

int solution[MAX], answer[MAX];
int converted[MAX];
int numEvents;

int computeResult(int row, int column)
{
	if(m[row][column] != -1)
	{
		return m[row][column];
	}

	if(row == 0 && column == 0)
	{
		if(converted[answer[0]] == 0)
		{
			m[0][0] = 1;
		}
		else
		{
			m[0][0] = 0;
		}
	}
	else if(row == 0)
	{
		if(converted[answer[0]] == column)
		{
			m[0][column] = computeResult(0, column - 1) + 1;
		}
		else
		{
			m[0][column] = computeResult(0, column - 1);
		}
	}
	else if(column == 0)
	{
		if(converted[answer[row]] == 0)
		{
			m[row][0] = computeResult(row - 1, 0) + 1;
		}
		else
		{
			m[row][0] = computeResult(row - 1, 0);
		}
	}
	else
	{
		if(converted[answer[row]] == column)
		{
			m[row][column] = computeResult(row - 1, column - 1) + 1;
		}
		else
		{
			m[row][column] = max(computeResult(row - 1, column), computeResult(row, column - 1));
		}
	}

	return m[row][column];
}

int main()
{
	int result;
	int temp;

	cin >> numEvents;

	for(int i = 0; i < numEvents; i++)
	{
		cin >> temp;
		solution[temp - 1] = i;		
		converted[i] = temp - 1;
	}

	while(true)
	{
		cin >> temp;

		if(cin.fail())
		{
			break;
		}

		answer[temp - 1] = 0;

		for(int i = 1; i < numEvents; i++)
		{			
			cin >> temp;
			answer[temp - 1] = i;
		}

		for(int i = 0; i < numEvents; i++)
		{

			for(int j = 0; j < numEvents; j++)
			{
				m[i][j] = -1;
			}
		}

		result = computeResult(numEvents - 1, numEvents - 1);

		cout << result << endl;
	}
}
