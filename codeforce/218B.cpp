#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int m,n;
	cin >> n >> m;
	priority_queue<int,vector<int>,less<int> > max;
	priority_queue<int,vector<int>,greater<int> > min;
	for(int i = 0;i < m;i++)
	{
		int tmp;
		cin >> tmp;
		max.push(tmp);
		min.push(tmp);
	}
	int maxnum = 0;
	int minnum = 0;
	for(int i = 0;i < n;i++)
	{
		int maxelement = max.top();
		int minelement = min.top();
		max.pop();
		min.pop();
		maxnum += maxelement;
		minnum += minelement;
		if(maxelement - 1 > 0)
			max.push(maxelement - 1);
		if(minelement - 1 > 0)
			min.push(minelement - 1);
	}
	cout << maxnum << " " << minnum << endl;
	return 0;
}
