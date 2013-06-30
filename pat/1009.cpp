#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 2001
using namespace std;

bool eq(double x,double y){
	return abs(x - y) < 1e-10;
}

int main(){
	double coe[MAX];
	for(int i = 0;i < MAX;i++)
		coe[i] = 0.0;
	int n1,n2;
	vector<pair<int,double> >x1,x2;
	scanf("%d",&n1);
	for(int i = 0;i < n1;i++){
		int exp;
		double coef;
		scanf("%d%lf",&exp,&coef);
		x1.push_back(make_pair(exp,coef));
	}
	scanf("%d",&n2);
	for(int i = 0;i < n2;i++){
		int exp;
		double coef;
		scanf("%d%lf",&exp,&coef);
		x2.push_back(make_pair(exp,coef));
	}
	
	for(int i = 0;i < x1.size();i++)
		for(int j = 0;j < x2.size();j++)
			coe[x1[i].first + x2[j].first] += x1[i].second * x2[j].second;
	int count = 0;
	for(int i = MAX - 1;i >= 0;i--)	
		if(!eq(coe[i],0.0))
			count++;
	printf("%d",count);
	for(int i = MAX - 1;i >= 0;i--)
		if(!eq(coe[i],0.0))
			printf(" %d %.1f",i,coe[i]);
	return 0;
}
