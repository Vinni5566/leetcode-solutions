class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> closest(n);
        closest[0] = 1;
        closest[n-1] = n-2;

        for(int i = 1; i < n-1; i++) {

            int l_diff = abs(nums[i] - nums[i-1]);
            int r_diff = abs(nums[i] - nums[i+1]);

            if(l_diff <= r_diff) {
                closest[i] = i-1;
            } else {
                closest[i] = i+1;
            }
        }

        vector<int> forward(n, 0);

        for(int i = 0; i < n-1; i++) {

            int cost = 0;
            
            if(closest[i] == i+1) {
                cost = 1;
            } else {
                cost = nums[i+1] - nums[i];
            }

            forward[i+1] = cost + forward[i];
        }

        vector<int> backward(n, 0);

        for(int i = 1; i < n; i++) {

            int cost = 0;
            
            if(closest[i] == i-1) {
                cost = 1;
            } else {
                cost = nums[i] - nums[i-1];
            }

            backward[i] = cost + backward[i-1];
        }
        

        int m = queries.size();
        vector<int> ans(m);

        for(int i = 0; i < m; i++) {

            int l = queries[i][0];
            int r = queries[i][1];

            if(l < r) {
                ans[i] = forward[r]-forward[l];
            }

            else if(l > r) {
                ans[i] = backward[l]-backward[r];
            }

            else {
                ans[i] = 0;
            }
        }

        return ans;
    }
};
