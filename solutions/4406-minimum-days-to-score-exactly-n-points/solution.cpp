class Solution {
public:
    int minDays(int n) {
        const int INF = 1e9;

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; ; k++) {
                int s = k * (k + 1) / 2;

                if (s > i) break;

                int r = i - s;
                int d = k;

                if (r > 0)
                    d += dp[r] + 1;

                dp[i] = min(dp[i], d);
            }
        }

        return dp[n];
    }
};
