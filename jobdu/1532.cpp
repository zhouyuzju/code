#include <iostream>
#include <cstdio>
#include <cstring>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int N;
	int board[8][8];
	while(scanf("%d",&N) != EOF){
		for(int i = 0;i < 8;i++)
			for(int j = 0;j < 8;j++)
				scanf("%d",&board[i][j]);
		bool dp[9][9][N + 1];
		memset(dp,0,9 * 9 * (N + 1));
		dp[1][1][board[0][0]] = true;
		for(int i = 0;i < 8;i++)
			for(int j = 0;j < 8;j++)
				for(int k = 1;k <= N;k++)
					if(k >= board[i][j])
						dp[i + 1][j + 1][k] |= (dp[i + 1][j][k - board[i][j]] | dp[i][j + 1][k - board[i][j]]);
		bool flag = false;
		for(int i = N;i > 0;i--)
			if(dp[8][8][i]){
				printf("%d\n",i);
				flag = true;
				break;
			}
		if(!flag)
			printf("-1\n");
	}
	return 0;
}
