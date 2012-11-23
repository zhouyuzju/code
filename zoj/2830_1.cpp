#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long long n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		cout << (n >> 1) << endl;
	}
	return 0;
}