class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> minEffort(m, vector<int>(n, INT_MAX));
        minEffort[0][0] = 0;

        priority_queue<vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        pq.push({0, 0, 0});

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int currEffort = top[0];
            int x = top[1];
            int y = top[2];

            //reached destination
            if (x == m - 1 && y == n - 1) return currEffort;

            // Skip stale entries
            if (currEffort > minEffort[x][y]) continue;

            //explore all possible paths
            for (auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int stepEffort = abs(heights[x][y] - heights[nx][ny]);
                    int newEffort = max(currEffort, stepEffort);

                    if (newEffort < minEffort[nx][ny]) {
                        minEffort[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }

        //min effort to reach destination
        return minEffort[m-1][n-1];
        
    }
};
