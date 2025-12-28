class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> mergedIntervals;

        // If no existing intervals
        if (intervals.empty()) {
            mergedIntervals.push_back(newInterval);
            return mergedIntervals;
        }

        bool isInserted = false;
        int remainingStartIndex = 0;

        for (int i = 0; i < intervals.size(); i++) {

            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];

            // Overlapping condition
            if (max(newInterval[0], currStart) <= min(newInterval[1], currEnd)) {
                newInterval[0] = min(newInterval[0], currStart);
                newInterval[1] = max(newInterval[1], currEnd);
            }
            else {
                // Current interval comes completely before newInterval
                if (currEnd < newInterval[0]) {
                    mergedIntervals.push_back(intervals[i]);
                }
                // New interval comes before current interval
                else {
                    mergedIntervals.push_back(newInterval);
                    isInserted = true;
                    remainingStartIndex = i;
                    break;
                }
            }
        }

        // If newInterval not inserted yet, add it
        if (!isInserted) {
            mergedIntervals.push_back(newInterval);
        }
        // Add remaining intervals
        else {
            for (int i = remainingStartIndex; i < intervals.size(); i++) {
                mergedIntervals.push_back(intervals[i]);
            }
        }

        return mergedIntervals;

        
    }
};
