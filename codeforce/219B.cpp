#include <iostream>
using namespace std;

long long powTen(int i)
{
	long long result = 1;
	for(int idx = 0;idx < i;idx++)
		result *= 10;
	return result;
}

int main()
{
	long long p,d;
	cin >> p >> d;
	long long max = p;
	long long tmp = p;
	int digit;
	for(int i = 1;;i++)
	{
		if(p - tmp > d)
			break;
		max = tmp;
		digit = i;
		//cout << "i:" << i << endl;
		if(p / powTen(i) == 0)
			break;
		tmp = (p / powTen(i) - 1) * powTen(i);
		for(int k = 0;k < i;k++)
			tmp += powTen(k) * 9;	
	}
	tmp = powTen(digit - 1) * 1 + max;
	if(p >= tmp)
		max = tmp;	
	cout << max << endl;
	return 0;
}
