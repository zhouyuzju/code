class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0)
            return word2.size();
        else if(word2.size() == 0)
            return word1.size();
        int m = word1.size();
        int n = word2.size();
        int dp[m + 1][n + 1];
        for(int i = 0;i <= m;i++)
            dp[i][0] = i;
        for(int i = 0;i <= n;i++)
            dp[0][i] = i;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(word1[i] == word2[j])
                    dp[i + 1][j + 1] = dp[i][j];
                else
                    dp[i + 1][j + 1] = min(dp[i][j + 1],min(dp[i][j],dp[i + 1][j])) + 1;
            }
        return dp[m][n];
    }
};

