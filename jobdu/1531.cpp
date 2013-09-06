#include <iostream>
#include <cstdio>
#include <cstring>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int N;
	while(scanf("%d",&N) != EOF){
		int money[N];
		for(int i = 0;i < N;i++)
			scanf("%d",&money[i]);
		bool dp[N + 1][10001];
		memset(dp,0,(N + 1) * 10001);
		for(int i = 0;i <= N;i++)
			dp[i][0] = true;	
		for(int i = 0;i < N;i++)
			for(int j = 1;j <= 10000;j++){
				dp[i + 1][j] |= dp[i][j];
				if(j >= money[i])
					dp[i + 1][j] |= dp[i][j - money[i]];
			}
		for(int i = 1;i <= 10000;i++)
			if(dp[N][i] == false){
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
