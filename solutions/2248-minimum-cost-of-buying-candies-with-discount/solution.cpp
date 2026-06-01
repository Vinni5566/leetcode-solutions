class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int n = cost.size();

        if(n == 1) return cost[0];
        if(n == 2) return cost[0]+cost[1];

        sort(cost.rbegin(), cost.rend());

        int totalCost = 0;
        int k = 0;

        for(int i = 0; i < n; i++) totalCost += cost[i];

        int discount = 0;

        for(int i = 2; i < n; i+=3) discount += cost[i];

        return totalCost - discount;
    }
};
