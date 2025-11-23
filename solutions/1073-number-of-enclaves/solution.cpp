class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2;  // 2 denotes boundary 1s
                }
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto& d: dir) {
                int dx = d.first;
                int dy = d.second;

                int nx = x + dx;
                int ny = y + dy;

                if((nx >= 0 && nx < m && ny >= 0 && ny < n) && (grid[nx][ny] == 1)) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) grid[i][j] = 1;
            }
        }

        return count;
    }
};
