class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res = grid;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int originalColor = grid[row][col];

        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = true;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            bool isBorder = false;

            for(auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                //out of bounds
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    isBorder = true;
                }
                //different color
                else if(grid[nx][ny] != originalColor) {
                    isBorder = true;
                }
                //same component
                else if(!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            if(isBorder) {
                res[x][y] = color;
            }
        }

        return res;

    }

    
};
