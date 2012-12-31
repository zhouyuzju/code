#include <iostream>
using namespace std;
int pow(int base,int n)
{
	int result = 1;
	for(int i = 0;i < n;i++)
		result *= base;
	return result;
}

int digits(int N)
{
	int result = 0;
	while(N > 0)
	{
		result++;
		N /= 10;
	}
	return result;
}
int main()
{
	int N;
	cin >> N;
	int digit = digits(N);
	int rn = pow(9,digit - 1);
	int ll = N / pow(10,digit - 1);
	int rest = 9 - (N % 10);
       	int result = ll * rn - 1;
	if(ll != 1)
		result -= rest;	
	cout << N - result << endl;
	return 0;
}
