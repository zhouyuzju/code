class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if(l1 + l2 != l3)
            return false;
        else if(l1 == 0)
            return s2 == s3;
        else if(l2 == 0)
            return s1 == s3;
        bool dp[l1 + 1][l2 + 1];
        dp[0][0] = true;
        for(int i = 1;i <= l1;i++)
            if(s1[i - 1] == s3[i - 1])
                dp[i][0] = dp[i - 1][0];
            else
                dp[i][0] = false;
        
        for(int i = 1;i <= l2;i++)
            if(s2[i - 1] == s3[i - 1])
                dp[0][i] = dp[0][i - 1];
            else
                dp[0][i] = false;
        
        for(int i = 1;i <= l1;i++)
            for(int j = 1;j <= l2;j++)
                dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]) || dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
        return dp[l1][l2];
    }
};

