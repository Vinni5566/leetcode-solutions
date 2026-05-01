class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();

        int totalSum = 0;

        for(int i = 0; i < n; i++) totalSum += nums[i];

        vector<int> dp(n);

        //calculate F(0)
        for(int i = 0; i < n; i++) {
            dp[0] += (i * nums[i]);
        }

        for(int k = 1; k < n; k++) {
            dp[k] = dp[k-1] + totalSum - (n * nums[n - k]);
        
        }

        int maxVal = *max_element(dp.begin(), dp.end());

        return maxVal;
    }
};
