#include <iostream>
#include <cstdio>
#include <set>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = 1000001;
int parent[MAX];
int h[MAX];

int root(int x){
	while(parent[x] != x)
		x = parent[x];
	return x;
}

void unine(int x,int y){
	int rx = root(x);
	int ry = root(y);
	if(h[rx] > h[ry]){
		parent[ry] = rx;
		h[ry]++;
	}
	else{
		parent[rx] = ry;
		h[rx]++;
	}
}

void find(int x){
	int r = root(x);
	while(parent[x] != x){
		int tmp = parent[x];
		parent[x] = r;
		h[x] = 2;
		x = tmp;
	}
}

int main(){
	while(true){
		int n,m;
		scanf("%d",&n);
		if(n == 0)
			break;
		scanf("%d",&m);
		for(int i = 1;i <= n;i++){
			parent[i] = i;
			h[i] = 1;
		}
		for(int i = 0;i < m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			unine(x,y);
		}
		for(int i = 1;i <= n;i++)
			find(i);
		set<int> aset;
		for(int i = 1;i <= n;i++)
			aset.insert(parent[i]);
		printf("%d\n",aset.size());
	}
	return 0;
}
