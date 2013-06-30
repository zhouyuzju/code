#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int main(){
	int n,m,k,t;
	vector<int> a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i < n;i++){
		scanf("%d",&t);
		a.push_back(t);
	}
	for(int i = 0;i < m;i++){
		scanf("%d",&t);
		b.push_back(t);
	}
	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());
	int i;
	for(i = 0;i < a.size() && i < b.size();i++){
		if(a[i] > b[i]){
			printf("YES\n");
			return 0;
		}
	}
	if(a.size() > b.size()){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}
