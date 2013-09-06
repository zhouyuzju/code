#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int colorNum;
	scanf("%d",&colorNum);
	map<int,int> favour;
	for(int i = 0;i < colorNum;i++){
		int num;
		scanf("%d",&num);
		favour[num] = i;
	}
	int stripeNum;
	scanf("%d",&stripeNum);
	vector<int> stripe;
	for(int i = 0;i < stripeNum;i++){
		int num;
		scanf("%d",&num);
		if(favour.find(num) != favour.end())
			stripe.push_back(favour[num]);
	}
	int size = stripe.size();
	int dp[size];
	for(int i = 0;i < size;i++)
		dp[i] = INT_MAX;
	for(int i = 0;i < size;i++){
		*upper_bound(dp,dp + size,stripe[i]) = stripe[i];
	}
	printf("%d\n",lower_bound(dp,dp + size,INT_MAX) - dp);
	return 0;
}
