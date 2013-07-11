class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit = 0;
        if(prices.size() == 0)
            return profit;
        int buy = prices[0];
        int sell = prices[0];
        for(int i = 1;i < prices.size();i++){
            if(buy > prices[i]){
                buy = prices[i];
                sell = prices[i];
            }
            if(sell < prices[i]){
                sell = prices[i];
            }
            profit = max(profit,sell - buy);
        }
        return profit;
    }
};

