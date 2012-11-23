#include <iostream>
#include <cmath>
#include <set>
using namespace std;

bool cal(long long a,int b)
{
	set<int> digita;
	set<int> digitb;
	while(a > 0)
	{
		digita.insert(a % 10);
		a /= 10;
	}
	while(b > 0)
	{
		digitb.insert(b % 10);
		b /= 10;
	}
	int count = 0;
	for(int i = 0;i < 10;i++)
	{
		if(digita.find(i) != digita.end() && digitb.find(i) != digitb.end())
		{
			count = 1;
			break;
		}
	}
	if(count == 1)
		return true;
	else
		return false;

}

int main()
{
	long long x;
	cin >> x;
	long long d;
	int count = 0;
	for(int i = 1;i <= sqrt(x);i++)
	{
		if(x % i == 0)
		{
			if(cal(x,i))
				count++;
			if(i != (x / i) && cal(x,x / i))
				count++;
		}
	}
	cout << count << endl;
	return 0;
}
