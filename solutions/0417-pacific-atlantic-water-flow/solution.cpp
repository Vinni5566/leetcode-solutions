class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> atl(m, vector<bool>(n));

        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;

        for (int i = 0; i < m; i++) {
            pac[i][0] = true;
            pq.push({i, 0});
        }

        for (int j = 0; j < n; j++) {
            if (!pac[0][j]) {
                pac[0][j] = true;
                pq.push({0, j});
            }
        }

        for (int i = 0; i < m; i++) {
            atl[i][n - 1] = true;
            aq.push({i, n - 1});
        }

        for (int j = 0; j < n; j++) {
            if (!atl[m - 1][j]) {
                atl[m - 1][j] = true;
                aq.push({m - 1, j});
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (vis[nr][nc])
                        continue;

                    if (heights[nr][nc] < heights[r][c])
                        continue;

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        };

        bfs(pq, pac);
        bfs(aq, atl);

        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};

