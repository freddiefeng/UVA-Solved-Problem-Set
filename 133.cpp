#include <iostream>
#include <list>

using namespace std;

struct Node
{
	int value;
	Node* pNext;
	Node* pPrev;
};

struct Ring
{
	Node* pCCW;
	Node* pCW;
};

void process(Ring & ring)
{
	if(ring.pCCW == ring.pCW)
	{
		Node * pCur = ring.pCCW;

		if(pCur->pPrev == pCur)
		{
			ring.pCCW = NULL;
			ring.pCW = NULL;

			cout.width(3);
			cout << pCur->value << endl;
		}
		else
		{
			ring.pCCW = pCur->pNext;
			ring.pCW = pCur->pPrev;
			ring.pCCW->pPrev = pCur->pPrev;
			ring.pCW->pNext = pCur->pNext;

			cout.width(3);
			cout << pCur->value << ",";
		}
	}
	else
	{
		Node * pLeft = ring.pCCW;
		Node * pRight = ring.pCW;

		if(ring.pCCW->pNext == ring.pCW)
		{
			if(ring.pCW->pNext == ring.pCCW)
			{
				ring.pCCW = NULL;
				ring.pCW = NULL;

				cout.width(3);
				cout << pLeft->value;
				cout.width(3);
				cout << pRight->value;
				cout << endl;
			}
			else
			{
				ring.pCCW = pRight->pNext;
				ring.pCW = pLeft->pPrev;
				ring.pCCW->pPrev = ring.pCW;
				ring.pCW->pNext = ring.pCCW;

				cout.width(3);
				cout << pLeft->value;
				cout.width(3);
				cout << pRight->value;
				cout << ",";
			}
		}
		else
		{
			ring.pCCW->pPrev->pNext = pLeft->pNext;
			ring.pCCW = pLeft->pNext;
			ring.pCCW->pPrev = pLeft->pPrev;

			ring.pCW->pNext->pPrev = pRight->pPrev;
			ring.pCW = pRight->pPrev;
			ring.pCW->pNext = pRight->pNext;

			cout.width(3);
			cout << pLeft->value;
			cout.width(3);
			cout << pRight->value;
			cout << ",";
		}
	}
}

int main()
{
	int N, k, m;
	Node buffer[20];

	while(true)
	{
		cin >> N >> k >> m;

		if(!N && !k && !m)
		{
			break;
		}

		Ring ring;
		buffer[0].value = 1;
		buffer[0].pPrev = NULL;
		buffer[0].pNext = NULL;
		ring.pCCW = &buffer[0];

		Node * pPrev = ring.pCCW;
		for(int i = 1; i < N; i++)
		{
			buffer[i].value = i + 1;
			buffer[i].pPrev = pPrev;
			buffer[i].pNext = NULL;
			pPrev->pNext = &buffer[i];

			pPrev = &buffer[i];
		}

		pPrev->pNext = ring.pCCW;
		ring.pCCW->pPrev = pPrev;
		ring.pCW = pPrev;

		Node * ccw = ring.pCCW;
		Node * cw = ring.pCW;

		while(ring.pCCW != NULL && ring.pCW != NULL)
		{
			for(int i = 0; i < k - 1; i++)
			{
				ring.pCCW = ring.pCCW->pNext;
			}

			for(int i = 0; i < m - 1; i++)
			{
				ring.pCW = ring.pCW->pPrev;
			}

			process(ring);
		}
	}
}
