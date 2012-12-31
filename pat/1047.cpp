#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int N,K;
	cin >> N >> K;
	vector<string> school[K + 1];
	for(int i = 1;i <= K;i++)
		school[i] = vector<string>();
	for(int i = 0;i < N;i++)
	{
		string name;
		cin >> name;
		int courseNum;
		cin >> courseNum;
		for(int j = 0;j < courseNum;j++)
		{
			int courseNo;
			cin >> courseNo;
			school[courseNo].push_back(name);
		}
	}
	for(int i = 1;i <= K;i++)
	{
		cout << i << " " << school[i].size() << endl;
		sort(school[i].begin(),school[i].end());
		vector<string>::iterator it = school[i].begin();
		for(;it != school[i].end();it++)
			cout << (*it) << endl;
	}
	return 0;
}
