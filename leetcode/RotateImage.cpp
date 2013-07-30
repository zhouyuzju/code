class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n == 0)
            return;
        for(int i = 0;i < (n + 1) / 2;i++)
            rotateCircle(matrix,n,i);
    }
private:
    void rotateCircle(vector<vector<int> >& matrix,int n,int k){
        if(k >= n - 1 - k)
            return;
        for(int i = 0;k + i < n - 1 - k;i++){
            int tmp = matrix[k][k + i];
            matrix[k][k + i] = matrix[n - 1 - k - i][k];
            matrix[n - 1 - k - i][k] = matrix[n - 1 - k][n - 1 - k - i];
            matrix[n - 1 - k][n - 1 - k - i] = matrix[k + i][n - 1 - k];
            matrix[k + i][n - 1 - k] = tmp;
        }
    }
};

