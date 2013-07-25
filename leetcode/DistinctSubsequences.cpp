class Solution {
public:
    int numDistinct(string S, string T) {
        int dp[T.length() + 1];
        for(int i = 0;i < T.length();i++)
            dp[i] = 0;
        dp[T.length()] = 1;
        for(int i = S.length() - 1;i >= 0;i--)
            for(int j = 0;j < T.length();j++)
                dp[j] += (S[i] == T[j]) * dp[j + 1];
        return dp[0];
    }
};

