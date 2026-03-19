class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> submatrixSum(n, vector<int>(m));
        submatrixSum[0][0] = grid[0][0];

        int res = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j > 0) {
                    submatrixSum[i][j] = submatrixSum[i][j-1] + grid[i][j];
                } else if(i > 0 && j == 0) {
                    submatrixSum[i][j] = submatrixSum[i-1][j]+grid[i][j];
                } else if(i > 0 && j > 0) {
                    submatrixSum[i][j] = submatrixSum[i-1][j] + submatrixSum[i][j-1] - submatrixSum[i-1][j-1] + grid[i][j];
                }

                if(submatrixSum[i][j] <= k) res++;
                else break;
            }
        }

        return res;
        
    }
};
