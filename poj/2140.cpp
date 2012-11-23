#include <iostream>
using namespace std;
int main()
{
	int N,count = 0;
	cin >> N;
	for(int i = 1;;i++)
	{
		if(i % 2 == 1 && N % i == 0 && N / i - i / 2 > 0)
			count++;
		else if(i % 2 == 0 && (N - i / 2) % i == 0)
		{
			int m = (N - i / 2) / i;
			if(m - i / 2 + 1> 0)
				count++;
			else
				break;
		}	
	}
	cout << count << endl;
	return 0;
}
