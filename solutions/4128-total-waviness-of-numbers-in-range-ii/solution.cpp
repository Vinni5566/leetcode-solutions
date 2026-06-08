class Solution {
public:
    long long totalWaviness(long long l, long long r) {
        using ll = long long;

        auto f = [&](ll x) -> ll {
            if (x < 100) return 0;

            string s = to_string(x);
            int n = s.size();

            ll dp1[16][10][10], dp2[16][10][10];
            memset(dp1, -1, sizeof(dp1));
            memset(dp2, -1, sizeof(dp2));

            auto dfs = [&](this auto&& dfs, int i, int p, int c,
                           bool lim, bool lead) -> pair<ll, ll> {
                if (i == n) return {1, 0};

                if (!lim && !lead && p >= 0 && c >= 0 &&
                    dp1[i][p][c] != -1) {
                    return {dp1[i][p][c], dp2[i][p][c]};
                }

                ll cnt = 0, sum = 0;
                int up = lim ? s[i] - '0' : 9;

                for (int d = 0; d <= up; d++) {
                    bool nl = lead && (d == 0);
                    int np = c;
                    int nc = nl ? -1 : d;

                    auto [c1, s1] = dfs(i + 1, np, nc, lim && (d == up), nl);

                    if (!nl && p >= 0 && c >= 0) {
                        if ((p < c && c > d) || (p > c && c < d))
                            sum += c1;
                    }

                    cnt += c1;
                    sum += s1;
                }

                if (!lim && !lead && p >= 0 && c >= 0) {
                    dp1[i][p][c] = cnt;
                    dp2[i][p][c] = sum;
                }

                return {cnt, sum};
            };

            return dfs(0, -1, -1, true, true).second;
        };

        return f(r) - f(l - 1);
    }
};
