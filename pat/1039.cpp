#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main()
{
	int N,K;
	string query;
	map<string,set<int> > lists;
	cin >> N >> K;
	for(int i = 0;i < K;i++)
	{
		int index,num;
		cin >> index >> num;
		string name;
		for(int j = 0;j < num;j++)
		{
			cin >> name;
			lists[name].insert(index);
		}
	}
	while(cin >> query)
	{
		cout << query << " " << lists[query].size();
		if(lists[query].size() > 0)
		{
			set<int>::iterator it = lists[query].begin();
			for(;it != lists[query].end();it++)
				cout << " " << (*it);
		}
		cout << endl;
	}
	return 0;
}
