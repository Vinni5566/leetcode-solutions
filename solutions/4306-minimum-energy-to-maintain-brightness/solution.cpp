class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        long long time = 0;

        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] <= end + 1) {
                end = max(end, intervals[i][1]);
            } else {
                time += end - start + 1;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        time += end - start + 1;

        long long bulbs = (brightness + 2) / 3;

        return time * bulbs;
    }
};
