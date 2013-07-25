class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1, 0);
        num[0] = 1;
        if(n > 0) num[1] = 1;
        for(int i = 2; i < n+1; i++) {
            for(int j = 0; j < i; j++) {
                num[i] += num[j]*num[i-j-1];
            }
        }
        return num[n];
    }
};

