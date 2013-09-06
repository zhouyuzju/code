class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() == 0)
            return;
        int idx = num.size() - 1;
        while(idx - 1 >= 0 && num[idx] <= num[idx - 1])
            idx--;
        if(idx == 0){
            sort(num.begin(),num.end());
            return;
        }
        int large = INT_MAX;
        int minidx = -1;
        for(int i = num.size() - 1;i >= idx;i--)
            if(num[i] > num[idx - 1] && num[i] < large){
                large = num[i];
                minidx = i;
            }
        int tmp = num[idx - 1];
        num[idx - 1] = num[minidx];
        num[minidx] = tmp;
        sort(num.end() - num.size() + idx,num.end());
    }
};

