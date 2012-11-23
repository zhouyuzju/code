#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;
int cmp(const void * a, const void * b)
{
	pair<int,int> aa = *((pair<int,int>*)a);
	pair<int,int> bb = *((pair<int,int>*)b);
	return aa.second - bb.second;
}

int main()
{
	int n,m,p;
	while(cin >> n >> m >> p)
	{
		pair<int,int>* problems = new pair<int,int>[n];
		priority_queue<pair<int,int> > pq;
		int a,b;
		for(int i = 0;i < n;i++)
		{
			cin >> a >> b;
			pair<int,int> problem = make_pair(b,a);
			problems[i] = problem;
		}
		
		qsort(problems,n,sizeof(pair<int,int>),cmp);

		/*for(int i = 0;i < n;i++)
		{
			cout << problems[i].first << "," <<problems[i].second << endl;
		}*/

		for(int i = 0, j = 0;i < m;i++)
		{
			for(;j < n && problems[j].second <= p;j++)
				pq.push(problems[j]);

			if(pq.empty())
				break;
			p += pq.top().first;
			pq.pop();
		}

		cout << p << endl;
		
		delete[] problems;
	}
	return 0;
}