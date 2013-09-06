#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int board[8][8];
	while(true){
		for(int i = 0;i < 8;i++)
			for(int j = 0;j < 8;j++)
				if(scanf("%d",&board[i][j]) == EOF)
					return 0;
		int dp[9][9] = {0};
		for(int i = 0;i < 8;i++)
			for(int j = 0;j < 8;j++)
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1],max(dp[i][j + 1],dp[i + 1][j]) + board[i][j]);
		printf("%d\n",dp[8][8]);
	}
	return 0;
}
