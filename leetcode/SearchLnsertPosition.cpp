class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(A == NULL || n == 0)
            return 0;
        int start = 0, end = n - 1;
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(A[mid] < target){
                if(mid == end || A[mid + 1] >= target)
                    return mid + 1;
                else
                    start = mid + 1;
            }
            else{
                if(mid == start || A[mid - 1] < target)
                    return mid;
                else
                    end = mid - 1;
            }
        }
        return mid;
    }
};

