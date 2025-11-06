class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();

        vector<vector<int>> dp(m);

        for(int i = 0; i < m; i++) {
            dp[i].resize(i+1, 0);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i+1; j++) {

                if(i == 0 && j == 0) {
                    dp[i][j] = triangle[i][j];
                } else if(j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                } else if(j == i) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }

        int minValue = dp[m-1][0];
        for(int j = 1; j < m; j++) {
            minValue = min(minValue, dp[m-1][j]);
        }

        return minValue;
    }
};
