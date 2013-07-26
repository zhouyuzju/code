class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(A == NULL || n <= 0)
            return 0;
        int cnt = 0,i = 0,j = n - 1;
        while(i <= j){
            if(A[i] == elem){
                cnt++;
                A[i] = A[j--];
            }
            else
                i++;
        }
        return n - cnt;
    }
};

