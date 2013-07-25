class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int idx = m + n - 1, i = m - 1,j = n - 1;
        while(i >= 0 && j >= 0){
            if(B[j] > A[i]){
                A[idx--] = B[j];
                j--;
            }
            else{
                A[idx--] = A[i];
                i--;
            }
        }
        for(int k = i;k >= 0;)
            A[idx--] = A[k--];
        for(int k = j;k >= 0;)
            A[idx--] = B[k--];
    }
};

