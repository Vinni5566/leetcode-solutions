class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));

        for(int i = 0; i < m-k+1; i++) {
            for(int j = 0; j < n-k+1; j++) {
                ans[i][j] = findMinAbsoluteDiff(i, j, m, n, k, grid);
            }
        }

        return ans;
        
    }

    int findMinAbsoluteDiff(int i, int j, int m, int n, int k, vector<vector<int>>& grid) {
        
        if(i+k > m || j+k > n) return 0;

        set<int> st;

        for(int r = i; r < i+k; r++) {
            for(int c = j; c < j+k; c++) {
                st.insert(grid[r][c]);
            }
        }

        if(st.size() == 1) return 0;

        int mini = INT_MAX;
        
        auto it = st.begin();
        auto prev = it;
        it++;
        
        for (; it != st.end(); it++) {
            mini = min(mini, abs(*it - *prev));
            prev = it;
        }

        return mini;
    }
};
