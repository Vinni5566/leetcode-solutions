class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();

        int start = image[sr][sc];
        if (start == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {

            int sz = q.size();
            for(int i = 0; i < sz; i++) {

                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(auto& d: dir) {
                    int dx = d.first;
                    int dy = d.second;

                    int nx = x + dx;
                    int ny = y + dy;

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == start) {
                        image[nx][ny] = color;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return image;
    }
};
