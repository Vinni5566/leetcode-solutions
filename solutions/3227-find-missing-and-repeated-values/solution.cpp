class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        vector<int> res(2);

        unordered_map<int, int> map;

        int n = grid.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[grid[i][j]]++;
            }
        }

        for(int i = 1; i <= n*n; i++) {
            
                if (map[i] == 2) {
                    res[0] = i;
                }
                
                if (map[i] == 0) {
                    res[1] = i;
                }
        }
        

        return res;
    }
};
