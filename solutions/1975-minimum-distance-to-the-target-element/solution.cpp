class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int n = nums.size();

        int absDiff = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {
                absDiff = min(absDiff, abs(i-start));
            }
        }

        return absDiff;
    }
};
