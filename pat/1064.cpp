#include <iostream>
#include <cstdio>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void inorder(int* node, int* level,int a,int& idx, int n){
	if(a > n)
		return;
	inorder(node,level,a * 2,idx,n);
	level[a] = node[idx++];
	inorder(node,level,2 * a + 1,idx,n);
}

int main(){
	int N;
	scanf("%d",&N);
	int node[N];
	for(int i = 0;i < N;i++)
		scanf("%d",&node[i]);
	sort(node,node + N);
	int level[N + 1];
	int t = 0;
	inorder(node,level,1,t,N);
	for(int i = 1;i <= N;i++)
		printf("%d%c",level[i],i == N ? '\n' : ' ');	
	return 0;

}
