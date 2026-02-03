class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();

        int p = -1;
        int q = -1;

        for(int i = 0; i < n-1; i++) {

            if(nums[i] < nums[i+1]) {
                continue;
            } else if(nums[i] == nums[i+1]) {
                return false;
            }else {
                p = i;
                break;
            }
        }

        if(p == -1 || p == 0) return false;

        for(int i = p; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                continue;
            } else if(nums[i] == nums[i+1]) {
                return false;
            } else {
                q = i;
                break;
            }
        }

        if(q == -1) return false;

        for(int i = q; i < n-1; i++) {
            if(nums[i] >= nums[i+1]) {
                return false;
            }
        }

        return true;
        
    }
};
