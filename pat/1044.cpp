#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	int num[N];
	int sum = 0, ans = INT_MAX,start = 0;
	vector<pair<int,int> > res;
	for(int i = 0;i < N;i++)
		scanf("%d",&num[i]);
	for(int i = -1;i < N;){
		if(sum < M){
			i++;
			if(i == N)
				break;
			sum += num[i];
			continue;
		}
		if(ans > sum - M){
			ans = sum - M;
			res.clear();
			res.push_back(make_pair(start,i));
		}
		else if(ans == sum - M)
			res.push_back(make_pair(start,i));
		sum -= num[start];
		start++;
	}
	for(int i = 0;i < res.size();i++)
		printf("%d-%d\n",res[i].first + 1,res[i].second + 1);
	return 0;
}
