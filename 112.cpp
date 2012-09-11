#include <iostream>
#include <stack>

using namespace std;

stack<int> results;
stack<char> states;

struct TreeNode
{
	/* data */
	int sum;
	TreeNode * leftChild;
	TreeNode * rightChild;
};

int main()
{
	char bracket;
	int value;
	int sum;

	while(true)
	{
		cin >> sum;

		if(cin.eof())
		{
			break;
		}

		cin >> bracket;
		while(bracket == ' ') cin >> bracket;

		if(bracket == '(')
		{
			states.push(bracket);
		}

		cin >> value;

		cin >> bracket;
		while(bracket == ' ') cin >> bracket;

		if(bracket == '(')
		{
			cout << "no" << endl;
			continue;
		}
	}
}