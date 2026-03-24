class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int cheapestPrice = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++) {
            
            cheapestPrice = min(cheapestPrice, prices[i]);
            maxProfit = max(maxProfit, (prices[i] - cheapestPrice));
        }

        return maxProfit;
        
    }
};
