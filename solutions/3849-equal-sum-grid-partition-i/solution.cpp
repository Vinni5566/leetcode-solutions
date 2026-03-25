class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        //checking if any horizontal cut makes the sum of the elements in both sections equal
        vector<long long> rowSum(m);

        for(int i = 0; i < m; i++) {
            long long currRowSum = 0;
            for(int j = 0; j < n; j++) {
                currRowSum += grid[i][j];
            }
            rowSum[i] = currRowSum;
        }


        vector<long long> prefixR(m);
        prefixR[0] = rowSum[0];

        vector<long long> suffixR(m);
        suffixR[m-1] = 0;

        for(int i = 1; i < m; i++) {
            prefixR[i] = rowSum[i] + prefixR[i-1];
        }

        for(int i = m-2; i >= 0; i--) {
            suffixR[i] = suffixR[i+1] + rowSum[i+1];
        }

        for(int i = 0; i < m; i++) {
            if(prefixR[i] == suffixR[i]) return true;
        }


        //checking if any vertical cut makes the sum of the elements in both sections equal

        vector<long long> colSum(n);

        for(int i = 0; i < n; i++) {
            long long currColSum = 0;
            for(int j = 0; j < m; j++) {
                currColSum += grid[j][i];
            }
            colSum[i] = currColSum;
        }


        vector<long long> prefixC(n);
        prefixC[0] = colSum[0];

        vector<long long> suffixC(n);
        suffixC[n-1] = 0;

        for(int i = 1; i < n; i++) {
            prefixC[i] = colSum[i] + prefixC[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            suffixC[i] = suffixC[i+1] + colSum[i+1];
        }

        for(int i = 0; i < n; i++) {
            if(prefixC[i] == suffixC[i]) return true;
        }

        return false;

    }
};
