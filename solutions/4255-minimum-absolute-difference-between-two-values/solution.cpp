class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {

        int n = nums.size();

        int minAbsoluteDiff = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[i] == 1 && nums[j] == 2) {
                    minAbsoluteDiff = min(minAbsoluteDiff, abs(i-j));
                }
            }
        }

        if(minAbsoluteDiff == INT_MAX) return -1;
        
        return minAbsoluteDiff;
        
    }
};
