#include <iostream>
#include <limits>

using namespace std;

char grid[50][50];

char word[50];

int nRow = 0, nCol = 0;

bool search_straight(int length, int i, int j, int i_incr, int j_incr)
{

	int x_end = i + (length - 1) * i_incr;
	int y_end = j + (length - 1) * j_incr;

	if(x_end < 0 || x_end >= nRow || y_end < 0 || y_end >= nCol) 
	{
		return false;
	}

	int index = 0;
	for(index = 0; index < length; index++)
	{
		if(word[index] != grid[i + i_incr * index][j + j_incr * index])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int nCases = 0, nWord = 0, length = 0, tmp = 0;
	bool found;
	char newLine;

	cin >> nCases;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n') ;

	while(nCases != 0)
	{
		cin >> nRow >> nCol;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n') ;

		for(int i = 0; i < nRow; i++)
		{
			cin.getline(grid[i], 51);
			for(int j = 0; j < nCol; j++) {grid[i][j] = tolower(grid[i][j]); /*cout << grid[i][j];*/}
		}

		cin >> nWord;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n') ;

		for(int i = 0; i < nWord; i++)
		{
			found = false;
			cin.getline(word, 51);

			length = 0;

			while(word[length] != '\0')
			{
				length++;
			}

			for(int index = 0; index < length; index++) word[index] = tolower(word[index]);

			int j = 0, k = 0;
			for(j = 0; j < nRow ; j++)
			{
				for(k = 0; k < nCol; k++)
				{
					if(search_straight(length, j, k, 1, 0) || 
						search_straight(length, j, k, 0, 1) || 
						search_straight(length, j, k, 1, 1) ||
						search_straight(length, j, k, -1, 0) ||
						search_straight(length, j, k, 0, -1) ||
						search_straight(length, j, k, -1, -1) ||
						search_straight(length, j, k, 1, -1) ||
						search_straight(length, j, k, -1, 1)) 
					{
						found = true;
						break;
					}
				}

				if(found) break;
			}

			if(found) cout << j + 1 << " " <<  k + 1 /*<< grid[j]*/ << endl;

		}

		nCases--;
		if(nCases != 0) cout << endl;
	}
}