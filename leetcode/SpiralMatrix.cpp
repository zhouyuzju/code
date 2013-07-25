class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        int minVal = min(matrix.size(),matrix[0].size());
        for(int i = 0;i < (minVal + 1) / 2;i++)
            fill(result,matrix,i);
        return result;
    }
private:
    void fill(vector<int>& result, vector<vector<int> >& matrix,int l){
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = l;i < n - l;i++)
            result.push_back(matrix[l][i]);
        for(int i = l + 1;i < m - l;i++)
            result.push_back(matrix[i][n - l - 1]);
        if(m - l - 1 > l)
            for(int i = n - 2 - l;i >= l;i--)
                result.push_back(matrix[m - l - 1][i]);
        if(l < n - l - 1)
            for(int i = m - l - 2;i >= l + 1;i--)
                result.push_back(matrix[i][l]);
    }
};

