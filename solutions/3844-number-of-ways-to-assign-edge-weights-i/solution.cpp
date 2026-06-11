class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        const long long MOD = 1e9 + 7;

        vector<vector<int>> g(n + 1);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        vector<int> vis(n + 1);

        q.push({1, 0});
        vis[1] = 1;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [u, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, depth + 1});
                }
            }
        }

        long long ans = 1;
        long long base = 2;
        int exp = maxDepth - 1;

        while (exp > 0) {
            if (exp & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }

        return (int)ans;
    }
};
