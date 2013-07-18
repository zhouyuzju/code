class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0)
            return 0;
        int dp[n + 1];
        for(int i = 0;i <= n;i++)
            dp[n] = INT_MIN;
        dp[0] = 0;
        for(int i = 0;i < n;i++)
            dp[i + 1] = max(dp[i] + A[i],A[i]);
        int max = INT_MIN;
        for(int i = 1;i <= n;i++)
            if(dp[i] > max)
                max = dp[i];
        return max;
    }
};

