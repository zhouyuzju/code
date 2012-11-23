#include <iostream>
using namespace std;

int main()
{
	long n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		int count = 0;
		while(n != 1)
		{
			if(n % 2 == 0)
				n /= 2;
			else
				n = n / 2 + 1;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}