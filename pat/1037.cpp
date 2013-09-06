#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int M,N;
	scanf("%d",&M);
	int a[M];
	for(int i = 0;i < M;i++)
		scanf("%d",&a[i]);
	scanf("%d",&N);
	int b[N];
	for(int i = 0;i < N;i++)
		scanf("%d",&b[i]);
	sort(a,a + M);sort(b,b + N);
	int k = min(M,N);
	long long sum1 = 0, sum2 = 0;
	for(int i = 0;i < k;i++){
		if(a[i] * b[i] > 0)
			sum1 += a[i] * b[i];
		if(a[M - i - 1] * b[N - i - 1] > 0)
			sum2 += a[M - i - 1] * b[N - i - 1];
	}
	printf("%lld\n",max(sum1,sum2));
	return 0;
}
