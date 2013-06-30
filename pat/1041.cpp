#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 10000
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int count[MAX] = {0};
	int num[N];
	for(int i = 0;i < N;i++){
		scanf("%d",&num[i]);
		count[num[i]]++;
	}
	for(int i = 0;i < N;i++){
		if(count[num[i]] == 1){
			printf("%d\n",num[i]);
			return 0;
		}
	}
	printf("None\n");
}
