#include <iostream>

using namespace std;

int main()
{
	long long left, right;

	while(cin >> left)
	{
		cin >> right;

		cout << (left >= right ? left - right : right - left) << endl; 
	}
}