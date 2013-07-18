class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        if(n == 0)
            return result;
        result.push_back(binarySearchLow(A,0,n - 1,target));
        result.push_back(binarySearchHigh(A,0,n - 1,target));
        return result;
    }
private:
    int binarySearchLow(int A[], int start, int end, int target){
        if(start > end)
            return -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(A[mid] == target && (mid == start || (mid > start && A[mid - 1] < target)))
                return mid;
            else if(A[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    
    int binarySearchHigh(int A[], int start, int end, int target){
        if(start > end)
            return -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(A[mid] == target && (mid == end || (mid < end && A[mid + 1] > target)))
                return mid;
            else if(A[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};

