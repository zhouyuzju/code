/*
ID:jwjzy10201
TASK:subset
LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("subset.in");
	ofstream fout ("subset.out");

	int N;
	fin >> N;
	int sum = (N + 1) * N / 2;
	if(sum % 2 != 0)
	{
		fout << 0 << endl;
		return 0;
	}
	sum /= 2;
	long long dp[N + 1][sum + 1];
	for(int i = 0;i < N + 1;i++)
		for(int j = 0;j < sum + 1;j++)
			dp[i][j] = 0;
	dp[1][1] = 1;
	dp[1][0] = 1;
	for(int i = 2;i <= N;i++)
		for(int j = 0; j <= sum;j++)
		{
			if(j - i >= 0)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
			else
				dp[i][j] = dp[i - 1][j];
		}
	fout << dp[N][sum] / 2 << endl;
	return 0;
}
