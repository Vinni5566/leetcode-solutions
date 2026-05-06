class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> res(n, vector<char>(m, '.'));

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                if(boxGrid[i][j] == '#') {

                    int idx = -1;

                    int k;

                    for(k = j+1; k < n; k++) {
                        if(boxGrid[i][k] == '.') {
                            idx = k;
                        } else {
                            break;
                        }
                    }

                    if(idx != -1) {
                        boxGrid[i][idx] = boxGrid[i][j];
                        boxGrid[i][j] = '.';
                    }
                }
                
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[j][m-i-1] = boxGrid[i][j];
            }
        }

        return res; 
        
    }
};
