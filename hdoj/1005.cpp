/**
 *Find the rules, F[n] = (A * F[n - 1] + B * F[n - 2]) % 7
 *loops at most 7 * 7 steps
 *2013/3/30
 **/
#include <cstdio>
using namespace std;
int main(){
	int A,B,n;
	while(true){
		scanf("%d%d%d",&A,&B,&n);
		if(A == 0 && B == 0 && n == 0)
			break;
		int f[64] = {0},i;
		f[1] = 1, f[2] = 1;
		for(i = 3;i <= 52;i++){
			f[i] = (A * f[i - 1] + B * f[i - 2]) % 7;
			if(f[i] == 1 && f[i - 1] == 1)
				break;
		}
		n %= (i - 2);	//trick here
		f[0] = f[i - 2];
		printf("%d\n",f[n]);
	}
	return 0;
}
