#include <cstdio>
#define MOD 1000000007
using namespace std;

long count = 0;
bool c[20] = {false},b[20] = {false};
int n;

void dfs(int p){
	if(p == n + 1){
		count++;
		return;		//get a c permutation
	}
	for(int i = 1;i <= n;i++){
		if(b[i])	
			continue;
		if(!c[(i + p - 2) % n]){
			b[i] = true;
			c[(i + p - 2) % n] = true;
			dfs(p + 1);
			//reset the choise
			c[(i + p - 2) % n] = false;
			b[i] = false;
		}
	}
	return;		//in case current permutation doesn't work
}


int main(){
	long long result[17] =  {-1,1,0,3,0,15,0,133,0,2025,0,37851,0,1030367,0,36362925,0};
	scanf("%d",&n);
	//dfs(1);
	long long num = result[n];
	for(int i = 2;i <= n;i++)
		num = (num * i) % MOD;
	printf("%I64d\n",num);
}
