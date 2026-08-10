class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        
        sort(prices.begin(), prices.end(), greater<>());

        sort(discounts.begin(), discounts.end(), greater<>());

        int idx = 0;

        double minTotalPrice = 0;

        for(int d : discounts) {
            int p = idx < prices.size() ? prices[idx] : 0;
            double currPrice = (p * (100 - d)) / 100.0;
            minTotalPrice += currPrice;

            idx++;
        }

        for(int i = idx; i < prices.size(); i++) {
            minTotalPrice += prices[i];
        }

        return minTotalPrice;

    }
};
