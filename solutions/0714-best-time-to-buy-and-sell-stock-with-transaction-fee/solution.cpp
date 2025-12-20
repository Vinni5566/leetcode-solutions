class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int hold = -prices[0];
        int sold = 0;

        for(int i = 1; i < prices.size(); i++) {

            int newHold = max(hold, (sold-prices[i]));
            int newSold = max(sold, hold + prices[i] - fee);
    
            sold = newSold;
            hold = newHold;
            
        }

        return sold;
    }
};
