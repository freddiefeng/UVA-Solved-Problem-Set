#include <iostream>
#include <cstring>

using namespace std;

int permutation[24][6] =
{
	// 1 to 2
	{2, 6, 3, 4, 1, 5},
	{2, 4, 6, 1, 3, 5},
	{2, 3, 1, 6, 4, 5},
	{2, 1, 4, 3, 6, 5},
	// 1 to 4
	{4, 2, 1, 6, 5, 3},
	{4, 5, 6, 1, 2, 3},
	{4, 1, 5, 2, 6, 3},
	{4, 6, 2, 5, 1, 3},
	//1 to 3
	{3, 2, 6, 1, 5, 4},
	{3, 5, 1, 6, 2, 4},
	{3, 1, 2, 5, 6, 4},
	{3, 6, 5, 2, 1, 4},
	// 1 to 5
	{5, 6, 4, 3, 1, 2},
	{5, 4, 1, 6, 3, 2},
	{5, 3, 6, 1, 4, 2},
	{5, 1, 3, 4, 6, 2},
	// 1 to 1
	{1, 2, 3, 4, 5, 6},
	{1, 5, 4, 3, 2, 6},
	{1, 3, 5, 2, 4, 6},
	{1, 4, 2, 5, 3, 6},
	// 1 to 6
	{6, 2, 4, 3, 5, 1},
	{6, 5, 3, 4, 2, 1},
	{6, 3, 2, 5, 4, 1},
	{6, 4, 5, 2, 3, 1}
};

int main()
{
	string s;
	const char * buffer;
	bool found;

	while(true)
	{
		found = false;

		// cin.getline(buffer, 12);

		cin >> s;

		if(cin.eof()) break;

		buffer = s.c_str();

		for(int i = 0; i < 24; i++)
		{
			if(buffer[permutation[i][0] - 1] == buffer[6] &&
				buffer[permutation[i][1] - 1] == buffer[7] &&
				buffer[permutation[i][2] - 1] == buffer[8] &&
				buffer[permutation[i][3] - 1] == buffer[9] &&
				buffer[permutation[i][4] - 1] == buffer[10] &&
				buffer[permutation[i][5] - 1] == buffer[11]
				)
			{
				cout << "TRUE" << endl;
				found = true;
				break;
			}
		}

		if(!found)
		{
			cout << "FALSE" << endl;
		}
	}
}