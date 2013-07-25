class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        bool dp[s1.size()][s2.size()][s1.size() + 1];
        for(int i = 0;i < s1.size();i++)
            for(int j = 0;j < s2.size();j++){
                dp[i][j][0] = true;
                dp[i][j][1] = (s1[i] == s2[j]);
                for(int k = 2;k <= s1.size();k++)
                    dp[i][j][k] = false;
            }
        for(int i = s1.size() - 1;i >= 0;i--)
            for(int j = s2.size() - 1;j >= 0;j--)
                for(int n = 2;n <= min(s1.size() - i,s2.size() - j);n++)
                    for(int k = 1;k < n;k++){
                        dp[i][j][n] |= ((dp[i][j][k] && dp[i + k][j + k][n - k]) || (dp[i][j + n - k][k] && dp[i + k][j][n - k]));
    
                        if(dp[i][j][n])
                            break;
                    }
        return dp[0][0][s1.size()];
    }
};

