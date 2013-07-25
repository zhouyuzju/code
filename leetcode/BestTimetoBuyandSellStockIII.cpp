/**
 * Very nice dp problem, abstract to maximum M segments sum problem
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int cov[3] = {0};
        int opt[3] = {0};
        
        for(int i = 0;i + 1 < prices.size();i++){
            int dif = prices[i + 1] - prices[i];
            int m = (i == 0 ? 1 : 2);
            for(int j = m;j >= 1;j--){
                cov[j] = max(opt[j - 1],cov[j]) + dif;
                opt[j] = max(opt[j],cov[j]);
            }
        }
        return max(opt[1],opt[2]);
    }
};

