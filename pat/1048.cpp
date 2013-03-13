#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N,M;
	cin >> N >> M;
	int coins[M + 1];
	fill(coins,coins + M + 1,0);
	for(int i = 0;i < N;i++)
	{
		int num;
		cin >> num;
		coins[num]++;
	}
	int minx = M + 1;
	for(int i = 1;i <= M;i++)
	{
		if(coins[i] != 0 && coins[M - i] != 0)
		{
			if(i != M - i && minx > i)
				minx = i;
			else if(i == M - i && coins[i] > 1 && minx > i)
				minx = i;
		}
	}
	if(minx == M + 1)
		cout << "No Solution" << endl;
	else
		cout << minx << " " << M - minx << endl;
	return 0;
}
