/**
 * Segment Tree
 * See codeforce 292E.
 **/
#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 1 << 20		//number of nodes in segment tree
#define INIT -1000000000	//init state of the node
#define MULTI -1000000001	//has multi value of the two sub nodes
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
struct node{
	int l,r,c;		//left node,right node and value of the current node
} segtree[MAX];

/**
 *construct segment tree and init the value of nodes with INIT state
 */
void init(int l,int r,int n){
	segtree[n].l = l;
	segtree[n].r = r;
	segtree[n].c = INIT;
	//printf("%d,%d,%d\n",l,r,n);
	//recursive init two child node,until l == r
	if(l != r){
		int mid = (l + r) / 2;
		init(l,mid,2 * n);
		init(mid + 1,r,2 * n + 1);
	}
}

/**
 * modify the value of a segment [l,r]
 */
void update(int l,int r,int n,int c){
	//PR(l);PR(r);PR(n);PR(c);
	//if current node's segment fit exactly [l,r],update the node's value and return
	if(segtree[n].l == l && segtree[n].r == r){
		segtree[n].c = c;
		return;
	}
	/* Lazy mark here!
	 * if current node's(segment) doesn't have two value which means all the sub segment's value equal to C or hasn't been assigned.
	 * Then copy current node's value to sub node's value and set current node's value state to MULTI,which means its sub nodes' has two type of value(maybe one just treat it two here)
	*/
	if(segtree[n].c != MULTI){
		segtree[2 * n].c = segtree[n].c;
		segtree[2 * n + 1].c = segtree[n].c;
		segtree[n].c = MULTI;
	}
	int mid = (segtree[n].l + segtree[n].r) / 2;
	//recursive update left or right or left and right node
	if(mid >= r)
		update(l,r,2 * n,c);
	else if(mid < l)
		update(l,r,2 * n + 1,c);
	else{
		update(l,mid,2 * n,c);
		update(mid + 1,r,2 * n + 1,c);
	}
}

/**
 * query segment[k]'s (the nth node of segtree array) value
 */
int query(int n,int k){
	//two cases here, the first is current node's(segment) value has not been assigned
	//the second is current node's(segment) value has exactly one value which means no need
	//to query sub tree
	if(segtree[n].c != MULTI)
		return segtree[n].c;
	int mid = (segtree[n].l + segtree[n].r) / 2;
	//recursive call left or right segment query
	//if l == r == k,then return;
	if(segtree[n].l <= k && mid >= k)
		return query(2 * n,k);
	else if(mid < k && k <= segtree[n].r)
		return query(2 * n + 1,k);
	else if(segtree[n].l == k && k == segtree[n].r){
		return segtree[n].c;
	}
}
//a test case of codeforce 292E
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
