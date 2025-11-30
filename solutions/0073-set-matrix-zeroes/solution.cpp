class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {

            int x =q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i = 0; i < n; i++) {
                matrix[x][i] = 0;
            }

            for(int i = 0; i < m; i++) {
                matrix[i][y] = 0;
            }
        }

        return;
    }
};
