class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0,j = n - 1;
        while(true){
            if(i > m - 1 || j < 0)
                return false;
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
    }
};

