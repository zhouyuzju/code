#include <iostream>
using namespace std;

int reverse(int N)
{
	int result = 0;
	while(N > 0)
	{
		result = result * 10 + N % 10;
		N /= 10;
	}
	return result;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		int x,y;
		cin >> x >> y;
//		cout << reverse(x) << "," << reverse(y) << endl;
		cout << reverse(reverse(x) + reverse(y)) << endl;
	}
	return 0;
}
