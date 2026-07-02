class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, -1));

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        int startHealth = health - grid[0][0];
        if(startHealth < 1) return false;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, startHealth});
        vis[0][0] = startHealth;

        while(!q.empty()) {

            auto cur = q.front();
            q.pop();

            int x = cur.first.first;
            int y = cur.first.second;
            int h = cur.second;

            if(x == m - 1 && y == n - 1)
                return true;

            for(auto &[dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {

                    int nh = h - grid[nx][ny];

                    if(nh >= 1 && nh > vis[nx][ny]) {
                        vis[nx][ny] = nh;
                        q.push({{nx, ny}, nh});
                    }
                }
            }
        }

        return false;
    }
};
