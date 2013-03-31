/**
 *Interesting problem, use three coordinate to represent a num such as(level,left,right),so
 *distance = abs(level(M) - level(N)) + abs(left(M) - left(N)) + abs(right(M) - right(N)),cause
 *the minimum distance always cross over the three direction line
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int level(int n){
	return sqrt(n - 1) + 1;
}

int pow(int base,int n){
	int result = 1;
	for(int i = 0;i < n;i++)
		result *= base;
	return result;
}

int left(int n){
	int l = level(n);
	return l - (pow(l, 2) + 1 - n) / 2;
}

int right(int n){
	return (pow(level(n), 2) - n) / 2 + 1;
}


int main(){
	int M,N;
	while(scanf("%d%d",&M,&N) != EOF){
		//printf("%d,%d,%d,%d,%d,%d\n",level(M),level(N),left(M),left(N),right(M),right(N));
		printf("%d\n",abs(level(M) - level(N)) + abs(left(M) - left(N)) + abs(right(M) - right(N)));
	}
}
