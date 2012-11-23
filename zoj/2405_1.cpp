#include <iostream>
using namespace std;

bool f(int n)
{
	int base10,base12,base16;
	base10 = n / 1000 + n / 10 % 10 + n / 100 % 10 + n % 10;
	base12 = n % 12 + n / 12 % 12 + n / 144 % 12 + n / 144 / 12 % 12;
	base16 = n % 16 + n / 16 % 16 + n / 256 % 16 + n / 256 / 16 % 16;
	if(base10 == base12 && base12 == base16)
		return true;
	else
		return false;
}

int main()
{
	int n = 2992;
	for(;n < 10000;n++)
	{
		if(f(n))
			cout << n << endl;
	}
	return 0;
}