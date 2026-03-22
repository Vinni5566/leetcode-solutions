class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int m = mat.size();
        int n = mat[0].size();

        if(mat == target) return true;

        for(int i = 1; i < 4; i++) {
            rotateMat(m, n, mat);
            if(mat == target) return true;
        }

        return false;
        
    }

    void rotateMat(int m, int n, vector<vector<int>>& mat) {

        for(int i = 0; i < m; i++) {
            for(int j = i+1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i = 0; i < m; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }

        return;
    }
};
