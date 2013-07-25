#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-8
#define PR(x) cout << #x << " = " << x << endl
#define MAX 1000001
using namespace std;

int h[MAX] = {0};

void swap(int* num, int a, int b){
	int tmp = num[a];
	num[a] = num[b];
	num[b] = tmp;
}

void swap(double* num, int a, int b){
	double tmp = num[a];
	num[a] = num[b];
	num[b] = tmp;
}

int quickfind(int* num, int lt, int gt, int target){
	//PR(lt);PR(gt);
	if(lt > gt)
		return -1;
	int i = lt;
	int j = gt + 1;
	int v = num[lt];
	while(i <= j){
		while(num[++i] > v) if(i == gt) break;
		while(num[--j] <= v) if(j == lt) break;
		if(i >= j)
			break;
		swap(num,i,j);
	}
	swap(num,lt,j);
	if(target < v)
		return quickfind(num,j + 1,gt,target);
	else if(target > v)
		return quickfind(num,lt,j - 1,target);
	else
		return j;
}

bool lessThan(double a, double b){
	if(abs(a - b) < EPS)
		return false;
	else if(a < b)
		return true;
	else
		return false;
}

bool lessOrEq(double a, double b){
	if(abs(a - b) < EPS)
		return true;
	else if(a < b)
		return true;
	else
		return false;
}

int quickfind(double* num, int lt, int gt, double target){
	if(lt > gt)
		return -1;
	int i = lt;
	int j = gt + 1;
	double v = num[lt];
	while(i <= j){
		while(lessThan(v,num[++i])) if(i == gt) break;
		while(lessOrEq(num[--j],v)) if(j == lt) break;
		if(i >= j)
			break;
		swap(num,i,j);
	}
	swap(num,lt,j);
	if(abs(v - target) < EPS)
		return j;
	else if(target < v)
		return quickfind(num,j + 1,gt,target);
	else if(target > v)
		return quickfind(num,lt,j - 1,target);
}

struct grade{
	int c,m,e;
	double a;
};

int main(){
	int N,K;
	int cnt = 1;
	scanf("%d%d",&N,&K);
	grade st[N + 1];
	int C[N + 1],M[N + 1],E[N + 1];
	double A[N + 1];
	for(int i = 0;i < N;i++){
		int id,c,m,e;
		scanf("%d%d%d%d",&id,&c,&m,&e);
		double avg = (c + m + e) / 3.0;
		h[id] = cnt;
		C[cnt] = c;M[cnt] = m;E[cnt] = e;A[cnt] = avg;
		grade tmp;
		tmp.c = c;tmp.m = m;tmp.e = e;tmp.a = avg;
		st[cnt] = tmp;
		cnt++;
	}
	for(int i = 0;i < K;i++){
		int id;
		scanf("%d",&id);
		int idx = h[id];
		if(idx == 0){
			printf("N/A\n");
			continue;
		}
		int c = quickfind(C,1,N,st[idx].c);
		int m = quickfind(M,1,N,st[idx].m);
		int e = quickfind(E,1,N,st[idx].e);
		int a = quickfind(A,1,N,st[idx].a);
		//PR(c);PR(m);PR(e);PR(a);
		char mark;
		int rank = N + 1;
		if(rank > a){
			rank = a;
			mark = 'A';
		}
		if(rank > c){
			rank = c;
			mark = 'C';
		}
		if(rank > m){
			rank = m;
			mark = 'M';
		}
		if(rank > e){
			rank = e;
			mark = 'E';
		}
		printf("%d %c\n",rank,mark);
	}
	return 0;
}
