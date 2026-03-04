class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> count1InRows(m, 0);
        vector<int> count1InColumns(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    count1InRows[i]++;
                    count1InColumns[j]++;
                }
            }
        }

        int countOfSpecialPositions = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    if(count1InRows[i] == 1 && count1InColumns[j] == 1) {
                        countOfSpecialPositions++;
                    }
                }
            }
        }

        return countOfSpecialPositions;
        
    }
};
