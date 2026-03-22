class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {

        int n = nums.size();

        unordered_map<int, int> dp;
        dp[0] = 0;

        for (int num : nums) {
            unordered_map<int, int> new_dp = dp;

            for (auto it : dp) {
                int old_xor = it.first;
                int size = it.second;

                int new_xor = old_xor ^ num;

                if (new_dp.find(new_xor) == new_dp.end()) {
                    new_dp[new_xor] = size + 1;
                } else {
                    new_dp[new_xor] = max(new_dp[new_xor], size + 1);
                }
            }

            dp = new_dp;
        }

        if (dp.find(target) == dp.end()) return -1;

        return n - dp[target];
    }
};
