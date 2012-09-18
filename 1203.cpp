#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int instructions[10000];

	memset(instructions, -1, sizeof(instructions));

	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

	string first;
	int id, period, nTask;
	pair<int, int> instr;
	while(true)
	{
		cin >> first;
		if(first == "#")
			break;
		cin >> id >> period;

		instructions[id] = period;
		instr = make_pair(period, id);
		pq.push(instr);
	}

	cin >> nTask;

	while(nTask--)
	{
		instr = pq.top();
		pq.pop();

		cout << instr.second  << endl;

		instr.first += instructions[instr.second];

		pq.push(instr);
	}
}