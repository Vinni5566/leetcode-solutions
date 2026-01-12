class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int n = points.size();
        int finalTime = 0;

        for (int i = 0; i < n - 1; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dx = points[i + 1][0];
            int dy = points[i + 1][1];

            int time = 0;

            //only vertical movement
            if (x == dx && y != dy) {
                time = abs(dy - y);
                finalTime += time;
                continue;
            }

            //only horizontal movement
            if (x != dx && y == dy) {
                time = abs(dx - x);
                finalTime += time;
                continue;
            }

            //diagonal or both x and y change
            int diffX = abs(dx - x);
            int diffY = abs(dy - y);

            //minimum time is max(dx, dy) because you can move diagonally
            time = max(diffX, diffY);

            finalTime += time;
        }

        return finalTime;
        
    }
};
