class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        bool flag = true;
        for(int i = 0;i < m;i++)
            if(obstacleGrid[i][0] == 0 && flag)
                dp[i][0] = 1;
            else{
                dp[i][0] = 0;
                flag = false;
            }
        flag = true;
        for(int i = 0;i < n;i++)
            if(obstacleGrid[0][i] == 0 && flag)
                dp[0][i] = 1;
            else{
                dp[0][i] = 0;
                flag = false;
            }
        for(int i = 1;i < m;i++)
            for(int j = 1;j < n;j++)
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
        return dp[m - 1][n - 1];
    }
};

