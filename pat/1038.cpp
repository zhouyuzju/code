#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool lessThan(string a,string b)
{
	string astr = a + b;
	string bstr = b + a; 
	int len = astr.length();
	for(int i = 0;i < 17;i++)
	{
		if(astr[i] < bstr[i])
			return true;
		else if(astr[i] > bstr[i])
			return false;
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	string nums[N];
	for(int i = 0;i < N;i++)
		cin >> nums[i];
	sort(nums,nums + N,lessThan);
	bool flag = false;
	for(int i = 0;i < N;i++)
	{
		if(nums[i] != "0")
		{
			if(!flag)
			{
				cout << atoi(nums[i].c_str());
			}
			else
				cout << nums[i];
			flag = true;
		}		
	}
	cout << endl;
	return 0;
}
