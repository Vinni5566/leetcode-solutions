class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> trailingZeros(m);

        for(int i = 0; i < m; i++) {

            int countConsecutive0s = 0;

            for(int j = n-1; j >= 0; j--) {
                if(grid[i][j] == 0) {
                    countConsecutive0s++;
                } else {
                    break;
                }
            }

            trailingZeros[i] = countConsecutive0s;
        }

        int minSwaps = 0;

        for(int i = 0; i < n; i++) {

            int required0s = n-i-1;

            int j = i;

            while(j < n && trailingZeros[j] < required0s) {
                j++;
            }

            if(j == n) return -1;

            minSwaps += (j-i);

            while(j > i) {
                swap(trailingZeros[j-1], trailingZeros[j]);
                j--;
            }

        }

        return minSwaps;
    }
};
