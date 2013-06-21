/**
 * Calculate the max sum among all the subarrays of the given array.
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <exception>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int maxSum(int* num,int length){
	if(num == NULL || length <= 0)
		throw new exception();
	int dp[length + 1];
	for(int i = 0;i <= length;i++)
		dp[i] = 0;
	int sum = 0x80000000;
	for(int i = 1;i <= length;i++){
		dp[i] = max(num[i - 1],dp[i - 1] + num[i - 1]);
		if(dp[i] > sum)
			sum = dp[i];
	}
	return sum;
}

int main(){
	int num[] = {1,-2,3,10,-4,7,2,-5};
	PR(maxSum(num,8));
	int num2[] = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};
	PR(maxSum(num2,10));
	int num3[] = {1,2,3,4,5,6,7,8,9,10};
	PR(maxSum(num3,10));
}
