class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int MOD = 1e9 + 7;
        
        int n = nums.size();

        int m = queries.size();

        for(int i = 0; i < m; i++) {

            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            for(int j = l; j <= r; j += k) {
                nums[j] = (1LL * (nums[j] % MOD) * v) % MOD;
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            res ^= nums[i];
        }

        return res;

    }
};
