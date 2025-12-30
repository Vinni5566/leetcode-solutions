class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int topRow = 0;
        int bottomRow = n - 1;
        
        while (topRow < bottomRow) {
            for (int col = 0; col < n; col++) {
                swap(matrix[topRow][col], matrix[bottomRow][col]);
            }
            
            topRow++;
            bottomRow--;
        }

        for (int row = 0; row < n; row++) {
            for (int col = row + 1; col < n; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        return;

    }
};
