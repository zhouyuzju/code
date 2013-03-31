#include <cstdio>
#include <cmath>
using namespace std;
bool mark[20] = {false};
int ans[20] = {-1};
int n;

bool isprimer(int n){
	for(int i = 2;i <= sqrt(n);i++)
		if(n % i == 0)
			return false;
	return true;
}

void dfs(int k){
	//printf("%d\n",k);
	if(k == n + 1 && isprimer(ans[1] + ans[n])){
		for(int i = 1;i <= n;i++)
			printf("%d%c",ans[i],i == n ? '\n' : ' ');
		return;
	}
	else if(k == n + 1)
		return;
	for(int i = 1;i <= n;i++){
		if(!mark[i] && isprimer(ans[k - 1] + i)){
			mark[i] = true;
			ans[k] = i;
			dfs(k + 1);
			ans[k] = -1;
			mark[i] = false;
		}
	}
	return;
}

int main(){
	int c = 1;
	while(scanf("%d",&n) != EOF){
		ans[1] = 1,mark[1] = true;
		printf("Case %d:\n",c++);
		dfs(2);
		printf("\n");
	}
}
