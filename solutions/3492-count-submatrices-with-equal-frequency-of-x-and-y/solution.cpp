class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

       vector<vector<pair<int, int>>> countOf_X_and_Y(n, vector<pair<int, int>>(m, {0, 0}));

       if(grid[0][0] == 'X') countOf_X_and_Y[0][0].first++;
       else if(grid[0][0] == 'Y') countOf_X_and_Y[0][0].second++;

       for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j > 0) {
                if(grid[i][j] == 'X') {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i][j-1].first+1, countOf_X_and_Y[i][j-1].second};
                } else if(grid[i][j] == 'Y') {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i][j-1].first, countOf_X_and_Y[i][j-1].second+1};
                } else {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i][j-1].first, countOf_X_and_Y[i][j-1].second};
                }
            } else if(i > 0 && j == 0) {
                if(grid[i][j] == 'X') {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i-1][j].first+1, countOf_X_and_Y[i-1][j].second};
                } else if(grid[i][j] == 'Y') {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i-1][j].first, countOf_X_and_Y[i-1][j].second+1};
                } else {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i-1][j].first, countOf_X_and_Y[i-1][j].second};
                }
            } else if(i > 0 && j > 0) {
                if(grid[i][j] == 'X') {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i-1][j].first+countOf_X_and_Y[i][j-1].first+1-countOf_X_and_Y[i-1][j-1].first, countOf_X_and_Y[i-1][j].second+countOf_X_and_Y[i][j-1].second-countOf_X_and_Y[i-1][j-1].second};
                } else if(grid[i][j] == 'Y') {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i-1][j].first+countOf_X_and_Y[i][j-1].first-countOf_X_and_Y[i-1][j-1].first, countOf_X_and_Y[i-1][j].second+countOf_X_and_Y[i][j-1].second-countOf_X_and_Y[i-1][j-1].second+1};
                } else {
                    countOf_X_and_Y[i][j] = {countOf_X_and_Y[i-1][j].first+countOf_X_and_Y[i][j-1].first-countOf_X_and_Y[i-1][j-1].first, countOf_X_and_Y[i-1][j].second+countOf_X_and_Y[i][j-1].second-countOf_X_and_Y[i-1][j-1].second};
                }
            }
        }
       }

       int res = 0;

       for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(countOf_X_and_Y[i][j].first == countOf_X_and_Y[i][j].second && countOf_X_and_Y[i][j].first != 0) res++;
        }
       }

       return res;
        
    }
};
