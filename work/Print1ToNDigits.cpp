/**
 * Print integer between 1 to n digits number
 */
#include <iostream>
#include <cstdio>
#include <exception>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void printArray(int* num, int d){
	for(int i = 0;i < d;i++)
		printf("%d",num[i]);
	printf("\n");
}

void dfs(int* num, int cur, int length){
	if(num[0] == 0)
		return;
	else if(cur == length){
		printArray(num, cur);
		return;
	}
	for(int i = 0;i < 10;i++){
		num[cur] = i;
		dfs(num, cur + 1, length);
		num[cur] = -1;
	}
}

void print(int n){
	if(n <= 0)
		throw new exception();
	int* num = new int[n];
	for(int i = 0;i < n;i++)
		num[i] = -1;
	for(int i = 0;i < n;i++)
		dfs(num,0,i + 1);
	delete [] num;
}

int main(){
	print(6);	
	return 0;
}
