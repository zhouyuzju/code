#include <cstdio>
using namespace std;

long long sum(int a,int b){
	long long result = 0;
	if(a == 2)
		result = 2;
	else
		result = (long long)(a + b) * (a - b + 1) / 2;	//cast to long to avoid int overflow
	return result;
}

int great(long long n,int s){
	int e = s - 2;
	if(n > sum(s,s - e))
		return s - e;
	while(n < sum(s,s - e) && e >= 1){
		e /= 2;
	}
	return s - e;
}

int main(){
	long long n;
	int k,count = 1;
	scanf("%I64d%d",&n,&k);
	if(n == 1){
		printf("0\n");
		return 0;
	}
	n -= k;
	int i = k - 1;
	while(n > 0){
		if(i < 2)
			break;
		int tmpI = great(n,i);
		n -= (sum(i,tmpI) - i + tmpI - 1);
		//printf("%I64d,%d\n",n,tmpI);
		count += (i - tmpI + 1);
		i = tmpI - 1;
		//printf("%d\n",count);
	}
	if(n > 0)
		printf("-1\n");
	else
		printf("%d\n",count);
}
