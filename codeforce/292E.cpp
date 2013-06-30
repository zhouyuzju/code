/**
 * Typical segment tree problem
 * 2013/4/18
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 1 << 20
#define INIT -1000000000
#define MULTI -1000000001
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
struct node{
	int l,r,c;
} segtree[MAX];

void init(int l,int r,int n){
	segtree[n].l = l;
	segtree[n].r = r;
	segtree[n].c = INIT;
	//printf("%d,%d,%d\n",l,r,n);
	if(l != r){
		int mid = (l + r) / 2;
		init(l,mid,2 * n);
		init(mid + 1,r,2 * n + 1);
	}
}

void update(int l,int r,int n,int c){
	//PR(l);PR(r);PR(n);PR(c);
	if(segtree[n].l == l && segtree[n].r == r){
		segtree[n].c = c;
		return;
	}
	if(segtree[n].c != MULTI){
		segtree[2 * n].c = segtree[n].c;
		segtree[2 * n + 1].c = segtree[n].c;
		segtree[n].c = MULTI;
	}
	int mid = (segtree[n].l + segtree[n].r) / 2;
	if(mid >= r)
		update(l,r,2 * n,c);
	else if(mid < l)
		update(l,r,2 * n + 1,c);
	else{
		update(l,mid,2 * n,c);
		update(mid + 1,r,2 * n + 1,c);
	}
}

int query(int n,int k){
	if(segtree[n].c != MULTI)
		return segtree[n].c;
	int mid = (segtree[n].l + segtree[n].r) / 2;
	if(segtree[n].l <= k && mid >= k)
		query(2 * n,k);
	else if(mid < k && k <= segtree[n].r)
		query(2 * n + 1,k);
	else if(segtree[n].l == k && k == segtree[n].r){
		return segtree[n].c;
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n + 1],b[n + 1];
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++)
		scanf("%d",&b[i]);
	init(1,n,1);
	for(int i = 0;i < m;i++){
		int t;
		scanf("%d",&t);
		if(t == 2){
			int k;
			scanf("%d",&k);
			int move = query(1,k);
			//for(int s = 1;s < 2 * n;s++)
			//	printf("%d,%d,%d\n",segtree[s].l,segtree[s].r,segtree[s].c);
			if(move == INIT)
				printf("%d\n",b[k]);
			else
				printf("%d\n",a[k + move]);
		}
		else if(t == 1){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			update(y,y + k - 1,1,x - y);
		}
	}
	return 0;
}
