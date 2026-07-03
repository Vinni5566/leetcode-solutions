class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> vals;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            vals.push_back(e[2]);
        }

        //topological order
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto check = [&](int mn) {
            const long long INF = 1e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &[v, w] : adj[u]) {
                    if (w < mn) continue;
                    if (v != n - 1 && !online[v]) continue;

                    dist[v] = min(dist[v], dist[u] + (long long)w);
                }
            }

            return dist[n - 1] <= k;
        };

        int l = 0;
        int r = vals.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(vals[mid])) {
                ans = vals[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
