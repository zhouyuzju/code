#include <iostream>
#include <cstdio>
#include <cmath>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 20
using namespace std;

bool isPrime(int a){
	if(a == 1)
		return false;
	for(int i = 2;i <= sqrt(a);i++)
		if(a % i == 0)
			return false;
	return true;
}

bool isReversePrime(int N, int D){
	int digit[MAX];
	int idx = 0;
	while(N > 0){
		digit[idx++] = N % D;
		N /= D;
	}
	int num = 0;
	int base = 1;
	for(int i = idx - 1;i >= 0;i--){	
		num += digit[i] * base;
		base *= D;
	}
	return isPrime(num);
}

int main(){
	int N,D;
	while(true){
		scanf("%d",&N);
		if(N < 0)
			break;
		scanf("%d",&D);
		if(N <= 1){
			printf("No\n");
			continue;
		}
		if(isPrime(N) && isReversePrime(N,D))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
