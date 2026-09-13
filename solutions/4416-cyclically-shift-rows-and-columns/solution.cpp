class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        for(int i = 0; i < n; i++) {
            vector<int> arr(n);

            for(int j = 0; j < n; j++) {
                arr[j] = grid[i][(j + rowShift[i]) % n];
            }

            grid[i] = arr;
        }

        for(int j = 0; j < n; j++) {
            vector<int> arr(n);

            for(int i = 0; i < n; i++) {
                arr[i] = grid[(i + colShift[j]) % n][j];
            }

            for(int i = 0; i < n; i++) {
                    grid[i][j] = arr[i];
            }
        }

        return grid;



    }
};
