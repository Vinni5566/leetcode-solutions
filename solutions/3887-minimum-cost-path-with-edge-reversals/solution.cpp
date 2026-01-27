class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (u == n - 1) {
                return dist[u];
            }

            if (visited[u]) continue;
            visited[u] = true;

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first;
                int w = graph[u][i].second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};
