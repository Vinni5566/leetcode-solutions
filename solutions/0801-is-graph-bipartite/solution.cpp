class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> adjacent(n, 0);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bfs(graph, visited, adjacent, i);
            }
        }

        for(int i = 0; i < graph.size(); i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                if(adjacent[i] == adjacent[graph[i][j]]) return false;
            }
        }

        return true;
   
    }

    void bfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& adjacent, int src) {

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : graph[u]) {
                if(!visited[v]) {
                    adjacent[v] = 1-adjacent[u];
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};
