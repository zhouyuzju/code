class Solution {
public:
    void sortColors(int A[], int n) {
        if(A == NULL || n <= 0)
            return;
        int cnt[3] = {0};
        for(int i = 0;i < n;i++)
            cnt[A[i]]++;
        int idx = 0;
        for(int i = 0;i < 3;i++)
            for(int j = 0;j < cnt[i];j++)
                A[idx++] = i;
    }
};

