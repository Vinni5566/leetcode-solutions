class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<bool> visited(isConnected.size(), false);
        int count = 0;

        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                bfsdis(isConnected, visited, i);
                count++;
            }
        }

        return count;

        
    }


    void bfsdis(vector<vector<int>>& isConnected, vector<bool>& visited, int src) {
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v = 0; v < isConnected.size(); v++) {
                if(isConnected[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }


};
