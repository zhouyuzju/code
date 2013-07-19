class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(A == NULL || n == 0)
            return 0;
        int i = 0,j = 1;
        for(;i < n && j < n;i++){
            for(;j < n && A[i] == A[j];j++);
            if(j < n)
                A[i + 1] = A[j];
        }
        return i == 0 ? 1 : i;
    }
};

