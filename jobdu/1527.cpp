#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int n;
int num[1000000];
int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 0;i < n;i++)
			scanf("%d",&num[i]);
		int sum = 0,summin = 0,maxVal = 0,allsum = 0,minVal = INT_MAX;
		for(int i = 0;i < n;i++){
			allsum += num[i];
			sum += num[i];
			summin += num[i];
			if(sum < 0)
				sum = 0;
			if(summin > 0)
				summin = 0;
			maxVal = max(maxVal,sum);
			minVal = min(minVal,summin);
		}
		printf("%d\n",max(maxVal,allsum - minVal));
	}
	return 0;
}
