class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<vector<int>> adj = buildGraph(n, manager);

        int minutes = 0;

        bfs(adj, informTime, minutes, headID);

        return minutes;
    }

    vector<vector<int>> buildGraph(int n, vector<int>& manager) {

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            if(manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }

        return adj;
    }

    void bfs(vector<vector<int>>& adj, vector<int>& informTime, int& minutes, int headID) {

        queue<pair<int, int>> q;
        q.push({headID, 0});

        while(!q.empty()) {

            auto [node, time] = q.front();
            q.pop();


            for(int sub : adj[node]) {

                int childTime = informTime[node] + time;
                q.push({sub, childTime});
                minutes = max(minutes, childTime);
            }
        }
    }


};
