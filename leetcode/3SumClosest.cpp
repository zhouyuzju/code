class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() <= 2)
            return 0;
        sort(num.begin(),num.end());
        int result = num[0] + num[1] + num[2];
        int gap = abs(result - target);
        for(int i = 0;i < num.size() - 2;i++){
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k){
                int sum = num[i] + num[j] + num[k];
                if(gap > abs(sum - target)){
                    gap = abs(sum - target);
                    result = sum;
                }
                if(sum == target)
                    return target;
                else if(sum > target)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};

