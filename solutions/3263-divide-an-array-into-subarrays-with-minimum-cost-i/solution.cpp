class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int n = nums.size();

        if(n == 3) return nums[0]+nums[1]+nums[2];

        int cost = INT_MAX;

        for(int i = 1; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                    cost = min(cost, nums[i]+nums[j]);
               
            }
        }

        return cost+nums[0];
        
    }
};
