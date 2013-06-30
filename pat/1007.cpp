#include <iostream>
#include <cstdio>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int N;
  	bool flag = false;
  	scanf("%d",&N);
  	int dp[N + 1],a[N + 1];
  	for(int i = 1; i <= N;i++){
    		scanf("%d",&a[i]);
    		if(a[i] >= 0)
      			flag = true;
  	}
  	dp[0] = 0x80000000;
  	dp[1] = a[1];
 	 for(int i = 2;i <= N;i++)
    		dp[i] = max(dp[i - 1] + a[i],a[i]);
  	int max = 0x80000000,idx = -1;
  	for(int i = 1;i <= N;i++)
    		if(max < dp[i]){
      			max = dp[i];
      			idx = i - 1;
    		}
  	int gt = a[idx + 1],lt,sum = max;
  	for(int i = idx;i >= 0;i--){
    		if(sum == a[i + 1]){
      			lt = a[i + 1];
      			break;
    		}
    		sum -= a[i + 1];
  	}
 	if(flag)
    		printf("%d %d %d\n",max,lt,gt);
  	else
    		printf("%d %d %d\n",0,a[1],a[N]);
  	return 0;
}

