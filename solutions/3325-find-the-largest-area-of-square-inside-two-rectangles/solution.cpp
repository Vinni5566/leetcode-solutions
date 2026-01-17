class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {

        int n = bottomLeft.size();

        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                //intersection coordinates
                int left   = max(bottomLeft[i][0], bottomLeft[j][0]);
                int right  = min(topRight[i][0],  topRight[j][0]);
                int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int top    = min(topRight[i][1],  topRight[j][1]);

                //check if intersection exists
                if (left < right && bottom < top) {
                    int w  = right - left;
                    int h = top - bottom;
                    int side = min(w, h);
                    maxArea = max(maxArea, 1LL * side * side);
                }

            }
        }
        return maxArea;
    }
};
