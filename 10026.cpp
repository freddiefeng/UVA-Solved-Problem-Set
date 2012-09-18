#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job
{
	int jobID;
	double effectiveCost;
};

Job jobs[1000];

bool compare(Job j1, Job j2)
{
	return j1.effectiveCost > j2.effectiveCost;
}

int main()
{
	int nCases, nJobs, days, fine;
	vector<Job> vJobs;
	bool bFirst = true;

	cin >> nCases;

	while(nCases--)
	{
		cin >> nJobs;

		for(int i = 0; i < nJobs; i++)
		{
			cin >> days >> fine;
			jobs[i].jobID = i + 1;
			jobs[i].effectiveCost = fine / (double) days;
		}

		vJobs.assign(jobs, jobs+nJobs);

		stable_sort(vJobs.begin(), vJobs.end(), compare);

		if(!bFirst)
		{
			cout << endl;
		}
		else
		{
			bFirst = false;
		}

		for(int i = 0; i < nJobs - 1; i++)
		{
			cout << vJobs[i].jobID << " ";
		}

		cout << vJobs[nJobs - 1].jobID << endl;
	}
}