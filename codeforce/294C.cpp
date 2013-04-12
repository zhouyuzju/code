#include <cstdio>
#define MOD 1000000007
#include <algorithm>
using namespace std;
int c[1001][1001];
long long pow2(int n){
	long long result = 1;
	for(int i = 1;i <= n;i++)
		result = (result * 2) % MOD;
	return result;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int p[m + 1],s[m + 1],old = 0;
	for(int i = 0;i <= n;i++)		//combination here
		for(int j = 0;j <= i;j++){
			if(j == 0 || j == i)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
			//printf("%d,%d,%d\n",i,j,c[i][j]);
		}
	for(int i = 0;i < m;i++)
		scanf("%d",&s[i]);
	sort(s,s + m);
	for(int i = 0;i < m;i++){
		p[i] = s[i] - old - 1;
		old = s[i];
	}
	p[m] = n - old;
	long long cnt = 0,result = 1;
	for(int i = 0;i <= m;i++){
		cnt += p[i];
		result = result * c[cnt][p[i]] % MOD;
		if(i > 0 && i < m)
			result = result * pow2(p[i] - 1) % MOD;
	}	
	printf("%d\n",result);
	return 0;
}
