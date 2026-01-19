class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> visited = grid;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 1) {
                    bfs(i, j, m, n, dir, visited, maxArea);

                }
            }
        }

        return maxArea;
        
    }

    void bfs(int i, int j, int m, int n, vector<pair<int, int>>& dir, vector<vector<int>>& visited, int& maxArea) {

        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = 0;

        int currArea = 1;

        while(!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(auto& d : dir) {

                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == 1) {
                    currArea += 1;
                    visited[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        maxArea = max(maxArea, currArea);
    }
};
