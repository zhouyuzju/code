class Solution {
public:
    int trap(int A[], int n) {
        if(A == NULL || n == 0)
            return 0;
        int mid = 0, water = 0;
        for(int i = 0;i < n;i++)
            if(A[i] > A[mid])
                mid = i;
        int h = 0;
        for(int i = 0;i < mid;i++){
            if(A[i] < h)
                water += h - A[i];
            else
                h = A[i];
        }
        h = 0;
        for(int i = n - 1;i > mid;i--){
            if(A[i] < h)
                water += h - A[i];
            else
                h = A[i];
        }
        return water;
    }
};

