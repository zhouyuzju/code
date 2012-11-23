#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool flag[1 << 16];
int sauce[1 << 16];

int cal(int mask)
{
	if(sauce[mask] == -1)
	{
		sauce[mask] = 0;
		for(int one = mask;one != 0;one = (one - 1) & mask)
		{
			if(flag[one])
			{
				sauce[mask] = max(sauce[mask],cal(mask ^ one) + 1);
			}
		}
	}
	return sauce[mask];
}
int main()
{
	int n,m,kind;
	while(cin >> n >> m)
	{
		fill(flag,flag + (1 << n),false);
		fill(sauce,sauce + (1 << n),-1);
		for(int i = 0;i < m;i++)
		{
			cin >> kind;
			int bit = 0,material;
			for(int j = 0;j < kind;j++)
			{
				cin >> material;
				bit |= 1 << (material - 1);
			}
			flag[bit] = true;
		}
		cout << cal((1 << n) - 1) << endl;
	}
	return 0;
}