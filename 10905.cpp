#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define MAX 50

using namespace std;

string numbers[50];

bool compare(string i, string j)
{
	string left = i + j;
	string right = j + i;

	return left > right;
}

int main()
{
	int nNumbers;

	while(true)
	{
		cin >> nNumbers;

		if(!nNumbers)
		{
			break;
		}

		for(int i = 0; i < nNumbers; i++)
		{
			cin >> numbers[i];
		}

		sort(numbers, numbers + nNumbers, compare);

		for(int i = 0; i < nNumbers; i++)
		{
			cout << numbers[i];
		}

		cout << endl;
	}
}