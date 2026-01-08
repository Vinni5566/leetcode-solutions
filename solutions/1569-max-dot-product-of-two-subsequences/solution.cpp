class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, INT_MIN));

        for(int i = n1-1; i >= 0; i--) {
            for(int j = n2-1; j >= 0; j--) {

                //pick both 
                int take = nums1[i]*nums2[j];
                if(dp[i+1][j+1] != INT_MIN) {
                    take += max(0, dp[i+1][j+1]);
                }

                //skip from nums1
                int skipI = dp[i+1][j];

                //skip from nums2
                int skipJ = dp[i][j+1];

                dp[i][j] = max({take, skipI, skipJ});

            }

        }

        return dp[0][0];
    }
};
