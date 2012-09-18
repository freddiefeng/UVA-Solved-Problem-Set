#include <iostream>

using namespace std;

#define BUFFER_SIZE 200

int piles[BUFFER_SIZE];

void compute(int position)
{
	int value;

	cin >> value;
	if(value != -1)
	{
		if(piles[position] == -1)
		{
			piles[position] = value;
		}
		else
		{
			piles[position] += value;
		}
		compute(position - 1);
		compute(position + 1);
	}

	return;
}

int main()
{
	int value;
	int count = 0;

	while(true)
	{
		for(int i = 0; i < BUFFER_SIZE; i++)
		{
			piles[i] = -1;
		}

		compute(100);
		count++;

		if(piles[100] == -1)
		{
			break;
		}

		cout << "Case " << count << ":" << endl;
		bool first = true;

		for(int i = 0; i < BUFFER_SIZE; i++)
		{
			if(piles[i] != -1)
			{
				if(!first)
				{
					cout << " ";
				}
				cout << piles[i];
				first = false;
			}
		}

		cout << endl;
		cout << endl;
	}
}