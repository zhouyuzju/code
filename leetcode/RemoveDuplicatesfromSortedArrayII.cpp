class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(A == NULL || n == 0)
            return 0;
        int i = 0,j = 0;
        for(;i < n && j < n;){
            int cnt = 0;
            for(;j < n && A[i] == A[j];j++)
                cnt++;
            if(j < n){
                if(cnt > 2){
                    A[i + 1] = A[i];
                    A[i + 2] = A[j];
                    i += 2;
                }
                else{
                    if(cnt == 2){
                        A[i + 1] = A[i];
                        A[i + 2] = A[j];
                        i += 2;
                    }
                    else{
                        A[i + 1] = A[j];
                        i++;
                    }
                }
            }
            else{
                if(cnt == 2){
                    A[i + 1] = A[i];
                    i += 2;
                }
                else if(cnt > 2){
                    A[i + 1] = A[i];
                    i += 2;
                }
                else
                    i++;
            }
        }
        return i == 0 ? 1 : i;
    }
};

