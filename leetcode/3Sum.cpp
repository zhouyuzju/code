class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() <= 2)
            return result;
        int n = num.size();
        sort(num.begin(),num.end());
        for(int i = 0;i < n - 2;i++){
            if(i > 0 && num[i] == num[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = num[i] + num[j] + num[k];
                if(sum == 0){
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[k]);
                    result.push_back(v);
                    int cmp = num[j];
                    while(j < k && num[j] == cmp)
                        j++;
                    cmp = num[k];
                    while(j < k && num[k] == cmp)
                        k--;
                }
                else if(sum > 0)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};

