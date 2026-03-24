class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int MOD = 12345;

        vector<vector<int>> prefix(n, vector<int>(m));

        vector<vector<int>> suffix(n, vector<int>(m));

        vector<vector<int>> p(n, vector<int>(m));


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    prefix[i][j] = 1;
                } else if(i > 0 && j == 0) {
                    prefix[i][j] = (1LL * prefix[i-1][m-1] * grid[i-1][m-1]) % MOD;
                } else {
                    prefix[i][j] = (1LL * prefix[i][j-1]*grid[i][j-1]) % MOD;
                }
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(i == n-1 && j == m-1) {
                    suffix[i][j] = 1;
                } else if(j == m-1) {
                    suffix[i][j] = (1LL * suffix[i+1][0] * grid[i+1][0]) % MOD;
                } else {
                    suffix[i][j] = (1LL * suffix[i][j+1]*grid[i][j+1]) % MOD;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                p[i][j] = (prefix[i][j] * suffix[i][j]) % MOD;
            }
        }

        return p;
        
    }
};
