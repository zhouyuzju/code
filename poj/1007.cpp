#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int sortedness(string s)
{
	int count = 0;
	for(int i = 0;i < s.length();i++)
	{
		char c = s[i];
		for(int j = i + 1;j < s.length();j++)
			if(s[j] < c)
				count++;
	}
	return count;
}

int main()
{
	int n,m;
	cin >> n >> m;
	string DNA[m];
	pair<int,int> sortArray[m];
	for(int i = 0;i < m;i++)
	{
		cin >> DNA[i];
		sortArray[i] = make_pair(sortedness(DNA[i]),i);
	}
	stable_sort(sortArray,sortArray + m);
	for(int i = 0;i < m;i++)
		cout << DNA[sortArray[i].second] << endl;
	return 0;
}
