#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int pairs[2][200];

int compare(const void *a,const void *b)
{
    return (*(int*)a)-(*(int*)b);
}

int main()
{
	int n = 0, d = 0, r = 0;
	long sum;

	while(true)
	{
		cin >> n >> d >> r;

		if(!n)
		{
			break;
		}

		for(int i = 0; i < n; i++)
		{
			cin >> pairs[0][i];
		}

		for(int i = 0; i < n; i++)
		{
			cin >> pairs[1][i];
		}

		sum = 0;
		int overtime;

		qsort(pairs[0],n,sizeof(int),compare);
        qsort(pairs[1],n,sizeof(int),compare);

		for(int i = 0; i < n; i++)
		{
			overtime = pairs[0][i] + pairs[1][n - 1 - i] - d;

			if(overtime > 0)
			{
				sum += overtime * r;
			}
		}

		cout << sum << endl;
	}
}

// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// using namespace std;

// int pairs[2][200];

// int compare(const void *a,const void *b)
// {
//     return (*(int*)a)-(*(int*)b);
// }
// int main()
// {
//     int i,n,d,r;
//     while(scanf("%d %d %d",&n,&d,&r))
//     {
//     	if(!n)
//     	{
//     		break;
//     	}

//         for (i=0;i<n;i++)
//             scanf("%d",&pairs[0][i]);
//         for (i=0;i<n;i++)
//             scanf("%d",&pairs[1][i]);
//         qsort(pairs[0],n,sizeof(int),compare);
//         qsort(pairs[1],n,sizeof(int),compare);
//         int x,ans[n];
//         for (i=0;i<n;i++)
//         {
//             x=pairs[0][i]+pairs[1][n-1-i];
//             if(x<=d)
//             ans[i]=0;
//             else ans[i]=x-d;
//         }
//         int sum;
//         sum=0;
//         for (i=0;i<n;i++)
//             sum=sum+ans[i]*r;
//         printf("%d\n",sum);

//     }
//     return 0;
// }