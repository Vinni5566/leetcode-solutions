class Solution {

    static bool cmp(const vector<int>& a, const vector<int>& b) {

            if(a[1] == b[1]) return a[0] < b[0];

            return a[1] > b[1];
    }

public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 1;

        int m_l = intervals[0][0];
        int m_r = intervals[0][1];

        for(int i = 1; i < n; i++) {

            int c_l = intervals[i][0];
            int c_r = intervals[i][1];

            if(m_l <= c_l && m_r >= c_r) {
                continue;
            }
            else {
                m_l = c_l;
                m_r = c_r;

                cnt++;
            }
        }

        return cnt;
        
    }
};
