#include <iostream>
#include <string>
using namespace std;
string a,b,ab;
int flag;

void f(int ai,int bi,int abi)
{
	if(flag == 1 || flag == -1)
		return;
	if(ai == a.length() && bi == b.length() && abi == ab.length())
	{
		flag = 1;
		return;
	}
	else if(ai == a.length() && bi == b.length() - 1 && b[bi] != ab[abi])
		flag = -1;
	else if(ai == a.length() - 1 && bi == b.length() && a[ai] != ab[abi])
		flag = -1;
	else if(ai == a.length() && b[bi] == ab[abi])
		f(ai,bi + 1,abi + 1);
	else if(bi == b.length() && a[ai] == ab[abi])
		f(ai + 1,bi,abi + 1);
	else if(ai < a.length() && bi < b.length())
	{
		if(a[ai] == ab[abi])
			f(ai + 1,bi,abi + 1);
		if(b[bi] == ab[abi])	
			f(ai,bi + 1,abi + 1);
	}
}

int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0;i < n;i++)
		{			
			cin >> a >> b >> ab;
			flag = 0;
			f(0,0,0);
			if(flag == 1)
				cout<< "Data set " << i + 1 << ": yes" << endl;
			else
				cout<< "Data set " << i + 1 << ": no" << endl;
		}
	}
	return 0;
}