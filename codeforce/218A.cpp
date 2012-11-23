#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int orig[2 * n + 1],input[2 * n + 1];
	for(int i = 0;i < 2 * n + 1;i++)
	{
		cin >> input[i];
		orig[i] = input[i];
	}
	int count = 0;
	for(int i = 1;i < 2 * n;i++)
	{
		if(input[i] - input[i - 1] > 1 && input[i] - input[i + 1] > 1)
		{
			orig[i]--;
			count++;
		}
		if(count == k)
			break;
	}
	for(int i = 0;i < 2 * n + 1;i++)
	{
		cout << orig[i];
		if(i != 2 * n)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}
