/**
 *print all the integers which has different digits in Octal
 */
#include <cstdio>
#include <iostream>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void dfs(int *a,int length,int cur){
	if(a == NULL)
		return;
	else if(length == cur){
		for(int i = 0;i < length;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	else if(length != 1 && a[0] == 0)
		return;
	else{
		for(int i = 0;i <= 7;i++){
			bool flag = true;
			for(int j = 0;j < cur;j++)
				if(a[j] == i){
					flag = false;
					break;
				}
			if(flag){
				a[cur] = i;
				dfs(a,length,cur + 1);
			}
		}
	}
}

void printDiffEight(){
	for(int i = 1;i <= 8;i++){
		int d[8] = {-1};
		dfs(d,i,0);
	}
}

int main(){
	printDiffEight();
	return 0;
}
