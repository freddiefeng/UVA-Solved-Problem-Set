#include <iostream>
#include <cstring>

using namespace std;

#define MAX 30000
#define nCoinValues 5

long long values[MAX+1];
long coinValues[nCoinValues] = {1, 5, 10, 25, 50};

int main()
{
	long cents;
	long max = 0;

	memset(values, 0, MAX+1);

	values[0] = 1;

	for(long i = 0; i < nCoinValues; i++)
	{
		for(long j = coinValues[i]; j <= MAX; j++)
		{
			values[j] += values[j - coinValues[i]];
		}
	}

	while(true)
	{
		cin >> cents;

		if(cin.fail())
		{
			break;
		}


		if(values[cents] == 1)
		{
			cout << "There is only 1 way to produce " << cents << " cents change." << endl;
		}
		else
		{
			cout << "There are " << values[cents] << " ways to produce " << cents << " cents change." << endl;
		}
	}
}