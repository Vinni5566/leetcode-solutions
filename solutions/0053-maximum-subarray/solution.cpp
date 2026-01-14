class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();

        //dp[i] = max subarray sum ending at i
        vector<int> dp(n, 0);

        //base case
        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            //either extend prev subarr or start a new one
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
        }

        int res = *max_element(dp.begin(), dp.end());

        //max subarr sum
        return res;

    }
};
