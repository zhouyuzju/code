class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        int sum[n];
        int d[n];
        for(int i = 0;i < n;i++){
            sum[i] = 0;
            d[i] = 0;
        }
        for(int i = 0;i < n;i++){
            vector<int> tmp = triangle[i];
            d[0] = sum[0] + tmp[0];
            if(tmp.size() > 1)
                d[tmp.size() - 1] = sum[tmp.size() - 2] + tmp[tmp.size() - 1];
            for(int j = 1;j < tmp.size() - 1;j++)
                d[j] = min(sum[j - 1],sum[j]) + tmp[j];
            for(int j = 0;j < tmp.size();j++)
                sum[j] = d[j];
        }
        int min = INT_MAX;
        for(int i = 0;i < n;i++)
            if(min > sum[i])
                min = sum[i];
        return min;
    }
};

