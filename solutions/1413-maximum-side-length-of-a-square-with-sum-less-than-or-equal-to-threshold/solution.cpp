class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int m = mat.size();
        int n = mat[0].size();

        //prefix sum
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        //build prefix sum
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j] = mat[i-1][j-1]
                           + pref[i-1][j]
                           + pref[i][j-1]
                           - pref[i-1][j-1];
            }
        }

        int left = 0;
        int right = min(m, n);
        int ans = 0;

        //binary search on side length
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(isPossible(mid, pref, m, n, threshold)) {
                ans = mid;          //mid is valid
                left = mid + 1;     //try bigger
            } else {
                right = mid - 1;    //try smaller
            }
        }

        return ans;
    }

    //check if any k x k square has sum <= threshold
    bool isPossible(int k,
                    vector<vector<int>>& pref,
                    int m, int n,
                    int threshold) {

        if(k == 0) return true;

        for(int i = k; i <= m; i++) {
            for(int j = k; j <= n; j++) {

                int squareSum =
                      pref[i][j]
                    - pref[i-k][j]
                    - pref[i][j-k]
                    + pref[i-k][j-k];

                if(squareSum <= threshold) {
                    return true;
                }
            }
        }

        return false;
    }
};
