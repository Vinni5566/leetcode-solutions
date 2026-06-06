class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {

        int n = nums.size();

        vector<long long> dp(2, -1e18);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            vector<long long> ndp(2, -1e18);

            for(int j = 0; j < 2; j++) {
                if(dp[j] < 0) continue;

                ndp[0] = max(ndp[0], dp[j]);

                if(!j && s[i] == '1') {
                    ndp[0] = max(ndp[0], dp[j]+nums[i]);
                }

                if(i+1 <n && s[i+1]=='1') {
                    ndp[1] = max(ndp[0], dp[j]+nums[i]);
                }
            }

            dp=ndp;
        }

        return max(dp[0], dp[1]);
    }
};

