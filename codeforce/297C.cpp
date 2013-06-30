/**
 * So trick! Just try to construct a and b array.
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int> >s;
	int a[n],b[n];
	for(int i = 0;i < n;i++){
		int si;
		scanf("%d",&si);
		s.push_back(make_pair(si,i));
	}
	sort(s.begin(),s.end());
	int t1 = (n + 2) / 3;
	for(int i = 0;i < t1;i++){
		int idx = s[i].second;
		a[idx] = i;
		b[idx] = s[i].first - a[idx];
	}
	for(int i = t1;i < 2 * t1 && i < n;i++){
		int idx = s[i].second;
		b[idx] = i;
		a[idx] = s[i].first - b[idx];
	}
	for(int i = 2 * t1;i < n;i++){
		int idx = s[i].second;
		b[idx] = n - 1 - i;
		a[idx] = s[i].first - b[idx];
	}
	printf("YES\n");
	for(int i = 0;i < n;i++)
		printf("%d%c",a[i],i == n - 1 ? '\n' : ' ');
	for(int i = 0;i < n;i++)
		printf("%d%c",b[i],i == n - 1 ? '\n' : ' ');
	return 0;
}
