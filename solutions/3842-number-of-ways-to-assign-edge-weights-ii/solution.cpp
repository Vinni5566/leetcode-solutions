class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        int n = edges.size() + 1;
        int MOD = 1e9 + 7;
        int LOG = 20;

        vector<vector<int>> g(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> depth(n + 1);
        vector<vector<int>> up(n + 1, vector<int>(LOG));

        function<void(int, int)> dfs = [&](int u, int p) {
            up[u][0] = p;

            for (int i = 1; i < LOG; i++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }

            for (int v : g[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };

        dfs(1, 0);

        vector<long long> pow2(n);
        pow2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);

            int diff = depth[a] - depth[b];

            for (int i = 0; i < LOG; i++) {
                if (diff & (1 << i)) {
                    a = up[a][i];
                }
            }

            if (a == b) return a;

            for (int i = LOG - 1; i >= 0; i--) {
                if (up[a][i] != up[b][i]) {
                    a = up[a][i];
                    b = up[b][i];
                }
            }

            return up[a][0];
        };

        vector<int> res;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int p = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[p];

            if (dist == 0) {
                res.push_back(0);
            } else {
                res.push_back(pow2[dist - 1]);
            }
        }

        return res;
    }
};
