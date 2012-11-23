#include <iostream>
using namespace std;
#define MAX 100000

int main()
{
	int n,m;
	cin >> n >> m;
	long long array[n];
	for(int i = 0;i < n;i++)
		cin >> array[i];
	for(int i = 0;i < m;i++)
	{
		int l,r;
		cin >> l >> r;
		int amap[MAX] = {0};
		for(int j = l - 1;j < r;j++)
		{
			if(array[j] <= MAX)
				amap[array[j]]++;
		}
		int count = 0;
		for(int j = l - 1;j < r;j++)
		{
			if(array[j] <= MAX && amap[array[j]] == array[j])
			{
				count++;
				amap[array[j]] = -1;
			}

		}
		cout << count << endl;
	}
	return 0;
}
