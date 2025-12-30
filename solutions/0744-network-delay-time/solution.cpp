class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // adjacency list: adj[u] = vector of {v, travelTime}
        vector<vector<pair<int,long long>>> adj(n + 1);
        for(auto &t : times) {
            int u = t[0], v = t[1];
            long long w = t[2]; // make edge weight long long
            adj[u].push_back({v, w});
        }

        // distance array (long long to avoid overflow)
        vector<long long> dist(n + 1, LLONG_MAX);
        dist[k] = 0;

        // min-heap: {currentTime, node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, k});

        while(!pq.empty()) {
            auto [currTime, u] = pq.top(); pq.pop();

            // skip stale entries
            if(currTime > dist[u]) continue;

            for(auto &[v, w] : adj[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // compute maximum time among all nodes
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == LLONG_MAX) return -1; // unreachable
            ans = max(ans, dist[i]);
        }

        return (int)ans;
    }
};
