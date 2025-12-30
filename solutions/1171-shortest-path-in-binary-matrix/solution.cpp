class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // start or end blocked
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

        vector<pair<int, int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        vector<vector<int>> length(m, vector<int>(n, -1));
        length[0][0] = 1;

        queue<pair<int,int>> q;
        q.push({0, 0});

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            // reached destination
            if (x == m-1 && y == n-1) {
                return length[x][y];
            }

            for(auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
                   grid[nx][ny] == 0 && length[nx][ny] == -1) {

                    length[nx][ny] = length[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
        
    }
};
