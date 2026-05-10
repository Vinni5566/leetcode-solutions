class Solution {

private:
    
    vector<vector<pair<int, long long>>> buildEmptyGraph(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, long long>>> adjEmpty(n);

        for(auto& edge : roads) {

            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adjEmpty[u].push_back({v, cost});
            adjEmpty[v].push_back({u, cost});
        }

        return adjEmpty;
    }

    vector<vector<pair<int, long long>>> buildLoadedGraph(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, long long>>> adjLoaded(n);

        for(auto& edge : roads) {
            int u = edge[0];
            int v = edge[1];
            long long cost = edge[2];
            long long tax = edge[3];

            adjLoaded[u].push_back({v, cost*tax});
            adjLoaded[v].push_back({u, cost*tax});
        }

        return adjLoaded;
    }

    vector<long long> dijkstra(vector<vector<pair<int, long long>>>& adj, int n, int i) {

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, i});

        dist[i] = 0;

        while(!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto& [v, wt] : adj[u]) {
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {

        int m = roads.size();

        if(m == 0) return prices;

        vector<vector<pair<int, long long>>> adjEmpty = buildEmptyGraph(n, roads);
        vector<vector<pair<int, long long>>> adjLoaded = buildLoadedGraph(n, roads);

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            vector<long long> d1 = dijkstra(adjEmpty, n, i);
            vector<long long> d2 = dijkstra(adjLoaded, n, i);

            ans[i] = prices[i];

            for(int j = 0; j < n; j++) {
                if (d1[j] == LLONG_MAX || d2[j] == LLONG_MAX) continue;
                ans[i] = min((long long)ans[i], d1[j]+d2[j]+prices[j]);
            }
        }

        return ans;   

    }
};
