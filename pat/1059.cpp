#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

bool isPrime(int n){
	bool result = true;
	for(int i = 2;i <= sqrt(n);i++)
		if(n % i == 0){
			result = false;
			break;
		}
	return result;
}

int nextPrime(int n){
	int num = n + 1;
	for(;!isPrime(num);num++);
	return num;
}

int main(){
	int N;
	scanf("%d",&N);
	map<int,int> result;
	int fact = 2;
	int num = N;
	if(num == 1){
		printf("1=1\n");
		return 0;
	}
	while(num > 1){
		if(num % fact == 0){
			result[fact]++;
			num /= fact;
		}
		else
			fact = nextPrime(fact);
	}
	printf("%d",N);
	for(map<int,int>::iterator it = result.begin();it != result.end();it++)
		if(it->second > 1)
			printf("%c%d^%d",it == result.begin() ? '=' : '*',it->first,it->second);
		else if(it->second == 1)
			printf("%c%d",it == result.begin() ? '=' : '*',it->first);
	printf("\n");
	return 0;
}
