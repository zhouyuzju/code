#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 100000
using namespace std;

int main(){
	int A,B,N;
	scanf("%d%d%d",&A,&B,&N);
	if(A == B){
		printf("%05d\n",A);
		return 0;
	}
	int link[MAX],cnt[MAX];
	for(int i = 0;i < MAX;i++){
		link[i] = -1;
		cnt[i] = 0;
	}
	for(int i = 0;i < N;i++){
		int a,b;
		char c;
		scanf("%d %c %d",&a,&c,&b);
		link[a] = b;
	}
	int start = A;
	for(;start != -1;start = link[start])
		cnt[start]++;
	for(start = B;start != -1 && cnt[start] == 0;start = link[start])
		;
	if(start == -1)
		printf("-1\n");
	else
		printf("%05d\n",start);
	return 0;
}
