#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
	if(s.length() <= 0)
            return 0;
        int n = s.length();
        int dp[n + 1];
        dp[0] = 0;
	for(int i = 1;i <= n;i++)
		dp[i] = 100000;
        for(int i = 0;i < n;i++){
            for(int j = 0;i - j >= 0 && i + j < n;j++)
                if(s[i - j] == s[i + j])
		    dp[i + j + 1] = min(dp[i + j + 1],min(dp[i + j] + 1,dp[i - j] + 1));
		else
                    break;
            for(int j = 0;i + 1 + j < n && i - j >= 0;j++)
		if(s[i - j] == s[i + j + 1])
		    dp[i + j + 2] = min(dp[i + j + 2],min(dp[i - j] + 1,dp[i + j + 1] + 1));
	    	else
		    break;
	}
        return dp[n] - 1;
    }
};

int main(){
	Solution* s = new Solution();
	string str = "abba";
	printf("%d\n",s->minCut(str));
	return 0;
}
