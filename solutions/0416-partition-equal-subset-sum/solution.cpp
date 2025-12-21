class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return false;
        if(n == 2) return nums[0] == nums[1];

        int totalSum = 0;

        for(int x : nums) totalSum += x;

        if(totalSum % 2 != 0) return false;

        int target = totalSum/2;

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false)); 

        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < target+1; j++) {

                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
        
    }
};
