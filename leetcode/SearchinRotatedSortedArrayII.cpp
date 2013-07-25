class Solution {
public:
    bool search(int A[], int n, int target) {
        if(A == NULL || n == 0)
            return false;
        int start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(A[mid] == target)
                return true;
            if(A[mid] > A[end]){
                if(A[start] <= target && target < A[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else if(A[mid] < A[end]){
                if(A[mid] < target && target <= A[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else{
                int k;
                for(k = mid;k < n;k++)
                    if(A[k] != A[mid])
                        break;
                if(k < n){
                    if(A[k] > A[mid] && target > A[mid])
                        start = mid + 1;
                    else if(A[k] < A[mid] && target < A[mid])
                        start = mid + 1;
                    else
                        end = mid - 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

