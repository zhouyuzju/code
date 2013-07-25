class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit = 0;
        if(prices.size() == 0)
            return profit;
        for(int i = 0;i  + 1< prices.size();i++)
           if(prices[i] < prices[i + 1])
                profit += prices[i + 1] - prices[i];
        return profit;
    }
};

