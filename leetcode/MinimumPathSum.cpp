class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int dp[m + 1][n + 1];
        for(int i = 0;i <= m;i++)
            for(int j = 0;j <= n;j++)
                dp[i][j] = INT_MAX;
        dp[0][0] = 0;dp[0][1] = 0;dp[1][0] = 0;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                dp[i + 1][j + 1] = min(dp[i][j + 1],dp[i + 1][j]) + grid[i][j];
        return dp[m][n];
    }
};

