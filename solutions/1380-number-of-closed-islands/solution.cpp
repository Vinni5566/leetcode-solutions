class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited = grid;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && visited[i][j] == 0) {
                    bfs(i, j, m, n, visited, dir);
                }
            }
        }

        int countOfClosedIslands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0) {
                    bfs(i, j, m, n, visited, dir);
                    countOfClosedIslands++;
                }
            }
        }

        return countOfClosedIslands;
        
    }

    void bfs(int i, int j, int m, int n, vector<vector<int>>& visited ,vector<pair<int, int>>& dir) {

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;

        while(!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(auto& d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
};
