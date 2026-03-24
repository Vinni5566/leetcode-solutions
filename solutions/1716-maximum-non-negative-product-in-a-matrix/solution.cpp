class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        
        const int mod = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>>(n));

        //base case
        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int i = 1; i < n; i++) {
            dp[0][i] = {dp[0][i-1].first*grid[0][i], dp[0][i-1].second*grid[0][i]};
        }

        for(int i = 1; i < m; i++) {
            dp[i][0] = {dp[i-1][0].first*grid[i][0], dp[i-1][0].second*grid[i][0]};
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                long long upMax = dp[i-1][j].first;
                long long upMin = dp[i-1][j].second;

                long long leftMax = dp[i][j-1].first;
                long long leftMin = dp[i][j-1].second;

                dp[i][j].first = max(max(upMax * grid[i][j], leftMax * grid[i][j]), max(upMin * grid[i][j], leftMin * grid[i][j]));
                dp[i][j].second = min(min(upMax * grid[i][j], leftMax * grid[i][j]), min(upMin * grid[i][j], leftMin * grid[i][j]));
            }
        }

        return dp[m-1][n-1].first < 0? -1 : (dp[m-1][n-1].first % mod);

    }
};
