class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        int l = x;
        int h = x+k-1;

        while(l < h) {

            for(int i = y; i <= y+k-1; i++) {
                int temp = grid[l][i];
                grid[l][i] = grid[h][i];
                grid[h][i] = temp;
            }

            l++;
            h--;
        }

        return grid;
        
    }
};
