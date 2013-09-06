#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        vector<int> c(256,0);
        int maxVal = INT_MIN;
        for(int i = 0;i < n;i++){
            dp[i + 1] = min(dp[i] + 1, i + 1 - c[s[i]]);
            c[s[i]] = i + 1;
            if(maxVal < dp[i + 1])
                maxVal = dp[i + 1];
        }
        return maxVal;   
    }
};

int main(){
	Solution* s = new Solution();
	printf("%d\n",s->lengthOfLongestSubstring("abcabcbb"));
	return 0;
}
