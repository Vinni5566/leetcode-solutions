class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        //buying separately
        long long separate = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        //buying both
        long long both = 1LL * (need1 > need2 ? need1 : need2) * costBoth;
        
        //buying mix
        long long mixed1 = 1LL * need1 * costBoth + (need2 - need1 > 0 ? 1LL * (need2 - need1) * cost2 : 0);
        long long mixed2 = 1LL * need2 * costBoth + (need1 - need2 > 0 ? 1LL * (need1 - need2) * cost1 : 0);

        //result
        long long result = min(separate, both);
        result = min(result, min(mixed1, mixed2));
        
        return result; //min cost to acquire
    }
};
