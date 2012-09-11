#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool isMatched(string cardA, string cardB)
{
	return (cardA[0] == cardB[0]) || (cardA[1] == cardB[1]);
}

void clearStacks(vector<stack<string> > * pCardStacks)
{
	for(vector<stack<string> >::iterator it = pCardStacks->begin(); it < pCardStacks->end(); it++)
	{
		while (!(*it).empty()) {
        	(*it).pop();
    	}
	}
}

int main()
{
	string input;

	while(true)
	{
		vector<stack<string> > cardStacks(52);

		cin >> input;

		if(input == "#") break;

		cardStacks[0].push(input);

		for(int i = 1; i < 52; i++)
		{
			cin >> input;

			cardStacks[i].push(input);
		}

		bool bMatch = true;
		string right, left_one, left_three;
		while(bMatch)
		{
			bMatch = false;

			for(vector<stack<string> >::iterator it = cardStacks.begin(); it < cardStacks.end();)
			{
				bMatch = false;

				right = it->top();

				if(it - 3 >= cardStacks.begin())
				{
					left_three = (it - 3)->top();

					if(isMatched(right, left_three))
					{
						bMatch = true;
						(it - 3)->push(right);
						it->pop();
						if(it->size() == 0)
						{
							it = cardStacks.erase(it);
						}
						it = it - 3;
					}
				}
				
				if(!bMatch && it - 1 >= cardStacks.begin())
				{
					left_one = (it - 1)->top();

					if(isMatched(right, left_one))
					{
						bMatch = true;
						(it - 1)->push(right);
						it->pop();
						if(it->size() == 0)
						{
							it = cardStacks.erase(it);
						}
						it = it - 1;
					}
				}

				if(!bMatch)
				{
					it++;
				}
			}
		}

		int nRemaining = cardStacks.size();
		cout << nRemaining 
			<< (nRemaining > 1 ? " piles remaining:" : " pile remaining:");

		for(int i = 0; i < nRemaining; i++)
		{
			cout << " " << cardStacks[i].size();
		}

		cout << endl;
	}

	return 0;
}
