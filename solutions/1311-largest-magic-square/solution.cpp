class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> d1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> d2(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }

        int ans = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int sum1 = d1[i + k][j + k] - d1[i][j];
                    int sum2 = d2[i + k][j] - d2[i][j + k];

                    if (sum1 != sum2) continue;

                    bool isMagic = true;

                    for (int x = 0; x < k; x++) {
                        int rSum = row[i + x][j + k] - row[i + x][j];
                        int cSum = col[i + k][j + x] - col[i][j + x];

                        if (rSum != sum1 || cSum != sum1) {
                            isMagic = false;
                            break;
                        }
                    }

                    if (isMagic) ans = max(ans, k);
                }
            }
        }

        return ans;

    }
};
