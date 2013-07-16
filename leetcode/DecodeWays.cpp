class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
            return 0;
        int dp[s.size() + 1];
        for(int i = 0;i <= s.size();i++)
            dp[i] = 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1;i < s.size();i++)
            if(s[i] == '0' && (s[i - 1] >= '3' || s[i - 1] == '0'))
                return 0;
            else if(s[i] == '0' && s[i - 1] >= '1' && s[i - 1] <= '2')
                dp[i + 1] += dp[i - 1];
            else if(s[i - 1] == '0' || s[i - 1] >= '3' || (s[i - 1] == '2' && s[i] > '6'))
                dp[i + 1] += dp[i];
            else
                dp[i + 1] += (dp[i - 1] + dp[i]);
        return dp[s.size()];
    }
};

