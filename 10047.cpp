#include <iostream>
#include <queue>
#include <limits>
#include <cstring>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define GREEN 0
#define WHITE 1
#define BLUE 2
#define RED 3
#define BLACK 4

typedef struct
{
	int row;
	int col;
	int direction;
	int color;
} squarestate;

int states[25][25][4][5];

int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int nRows, nCols;
int startRow, startCol, endRow, endCol;

bool isReached(squarestate state)
{
	if(state.row == endRow && state.col == endCol && state.color == GREEN)
	{
		return true;
	}

	return false;
}


int main()
{
	int caseCounter = 1;

	while(true)
	{
		cin >> nRows;
		if(!nRows)
			break;
		cin >> nCols;

		if(caseCounter != 1)
		{
			cout << endl;
		}

		char temp;
		queue<squarestate> stateQ;

		for(int i = 0; i < nRows; i++)
		{
			for(int j = 0; j < nCols; j++)
			{
				cin >> temp;
				memset(states[i][j], -1, sizeof(states[i][j]));
				switch (temp)
				{
					case '#':
						memset(states[i][j], -2, sizeof(states[i][j]));
						break;
					case 'S':
						startRow = i;
						startCol = j;
						break;
					case 'T':
						endRow = i;
						endCol = j;
						break;
					default:
						break;
				}
			}
		}


		bool reachable = false;
		squarestate state = {startRow, startCol, NORTH, GREEN};
		states[startRow][startCol][NORTH][GREEN] = 0;
		stateQ.push(state);

		while(!stateQ.empty())
		{
			int row, col, direction, color;
			squarestate prev_state = stateQ.front();
			stateQ.pop();

			row = prev_state.row + directions[prev_state.direction][0];
			col = prev_state.col + directions[prev_state.direction][1];
			direction = prev_state.direction;
			color = (prev_state.color + 1) % 5;

			if(row < nRows && row >= 0 && col < nCols && col >= 0
				&& states[row][col][direction][color] == -1)
			{
				squarestate new_state = {row, col, direction, color};
				states[row][col][direction][color] = 
				states[prev_state.row][prev_state.col][prev_state.direction][prev_state.color] + 1;

				if(isReached(new_state))
				{
					reachable = true;
					break;
				}

				stateQ.push(new_state);
			}

			row = prev_state.row;
			col = prev_state.col;
			direction = (prev_state.direction - 1) == -1 ? 3 : prev_state.direction - 1;
			color = prev_state.color;

			if(states[row][col][direction][color] == -1)
			{
				squarestate new_state = {row, col, direction, color};
				states[row][col][direction][color] = 
				states[prev_state.row][prev_state.col][prev_state.direction][prev_state.color] + 1;
				stateQ.push(new_state);
			}


			direction = (prev_state.direction + 1) % 4;

			if(states[row][col][direction][color] == -1)
			{
				squarestate new_state = {row, col, direction, color};
				states[row][col][direction][color] = 
				states[prev_state.row][prev_state.col][prev_state.direction][prev_state.color] + 1;
				stateQ.push(new_state);
			}
		}

		cout << "Case #" << caseCounter << endl;
		if(reachable)
		{
			int min = numeric_limits<int>::max();

			for(int i = 0; i < 4; i++)
			{
				if(states[endRow][endCol][i][GREEN] > 0 && states[endRow][endCol][i][GREEN] < min)
				{
					min = states[endRow][endCol][i][GREEN];
				}
			}

			cout << "minimum time = " << min << " sec" << endl;
		}
		else
		{
			cout << "destination not reachable" << endl;
		}

		caseCounter += 1;
	}

}