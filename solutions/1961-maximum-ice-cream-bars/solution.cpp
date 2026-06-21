class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());

        int res = 0;

        for(int cost : costs) {
            if(cost > coins) {
                break;
            } else {
                coins -= cost;
                res++;
            }
        }

        return res;
    }
};
