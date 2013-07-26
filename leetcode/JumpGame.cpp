class Solution {
public:
    bool canJump(int A[], int n) {
        if(A == NULL || n <= 0)
            return true;
        int max = 0;
        for(int i = 0;i < n;i++){
            if(max >= i && max < i + A[i])
                max = i + A[i];
        }
        return max >= n - 1;
    }
};

