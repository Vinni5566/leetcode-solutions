class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int n = nums.size();
        
        int idx = -1;

        for(int i = 0; i < n-1; i++) {
            if(nums[i] >= nums[i+1]) {
                idx = i;
            }
        }

        if(idx == -1) return 0;

        return idx+1;

        
        
    }
};
