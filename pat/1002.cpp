#include <cstdio>
#include <iostream>
#include <cmath>
#define PR(x) cout << #x << " = " << x << endl
#define N 1001
#define EPS 1e-16
using namespace std;
int main(){
	int ka,kb;
	double ca[N] = {0.0},cb[N] = {0.0};
	scanf("%d",&ka);
	int e;
	double c;
	for(int i = 0;i < ka;i++){
		scanf("%d%lf",&e,&c);
		ca[e] = c;
	}
	scanf("%d",&kb);
	for(int i = 0;i < kb;i++){
		scanf("%d%lf",&e,&c);
		cb[e] = c;
	}
	int count = 0;
	for(int i = N - 1;i >= 0;i--){
		double sum = ca[i] + cb[i];
		if(abs(sum - 0.0) < EPS)
			continue;
		else
			count++;
	}
	printf("%d",count);
	for(int i = N - 1;i >= 0;i--){
		double sum = ca[i] + cb[i];
		if(abs(sum - 0.0) < EPS)
			continue;
		else{
			printf(" %d %.1f",i,sum);
		}
	}
	return 0;
}
