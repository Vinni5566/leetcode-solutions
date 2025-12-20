class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int hold = -prices[0];
        int sold = 0;
        int nothing = 0;

        for(int i = 1; i < prices.size(); i++) {

            int newHold = max(hold, (nothing-prices[i]));
            int newSold = hold + prices[i];
            int newNothing = max(nothing, sold);

            sold = newSold;
            hold = newHold;
            nothing = newNothing;
            
            
        }

        return max(sold, nothing);

    }
};
