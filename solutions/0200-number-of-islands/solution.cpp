class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<char>> visited = grid;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int countOfIslands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(visited[i][j] == '1') {
                    bfs(dir, i, j, grid, m ,n, visited);
                    countOfIslands++;
                }
                
            }
        }

        return countOfIslands;
    }

    void bfs(vector<pair<int, int>>& dir, int i, int j, vector<vector<char>>& grid, int m, int n, vector<vector<char>>& visited) {

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = '0';

        while(!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(auto& d : dir) {

                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == '1') {
                    q.push({nx, ny});
                    visited[nx][ny] = '0';
                }
            }

            
        }
    }
};
