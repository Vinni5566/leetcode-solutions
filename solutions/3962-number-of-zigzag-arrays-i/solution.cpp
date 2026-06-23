class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        
        int mod = 1e9 + 7;
        int m = r - l + 1;

        long long dp[2001][2001][2];

        for (int v = 1; v <= m; v++) {
            dp[n][v][0] = 1;
            dp[n][v][1] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {

            vector<long long> p0(m + 1, 0);
            vector<long long> p1(m + 1, 0);

            for (int v = 1; v <= m; v++) {
                p0[v] = (p0[v - 1] + dp[i + 1][v][0]) % mod;
                p1[v] = (p1[v - 1] + dp[i + 1][v][1]) % mod;
            }

            for (int v = 1; v <= m; v++) {
                dp[i][v][1] = (p0[m] - p0[v] + mod) % mod;
                dp[i][v][0] = p1[v - 1];
            }
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans = (ans + dp[1][v][1]) % mod;
            ans = (ans + dp[1][v][0]) % mod;
        }

        return (int)ans;
    }
};
