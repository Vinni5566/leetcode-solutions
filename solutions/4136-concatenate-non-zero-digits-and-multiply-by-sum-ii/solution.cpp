class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const int mod = 1e9 + 7;

        vector<pair<int,int>> nonZero;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '0')
                nonZero.push_back({i, s[i] - '0'});
        }

        int m = nonZero.size();

        vector<long long> pw(m + 1, 1);
        for(int i = 1; i <= m; i++)
            pw[i] = (pw[i - 1] * 10) % mod;

        
        vector<long long> pre(m + 1, 0);
        vector<long long> sum(m + 1, 0);

        for(int i = 0; i < m; i++) {
            pre[i + 1] = (pre[i] * 10 + nonZero[i].second) % mod;
            sum[i + 1] = sum[i] + nonZero[i].second;
        }

        vector<int> ans;

        for(auto &q : queries) {

            int l = q[0], r = q[1];

            int L = lower_bound(nonZero.begin(), nonZero.end(), make_pair(l, 0))-nonZero.begin();
            int R = upper_bound(nonZero.begin(), nonZero.end(), make_pair(r, 9))-nonZero.begin()-1;

            if(L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (pre[R + 1] - pre[L] * pw[len] % mod + mod) % mod;
            long long digitSum = sum[R + 1] - sum[L];

            ans.push_back(x * digitSum % mod);
        }

        return ans;
    }
};
