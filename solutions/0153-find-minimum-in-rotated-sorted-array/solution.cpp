class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        
        int k = 0;

        for(int i = 0; i <  n-1; i++) {
            if(nums[i] > nums[i+1]) {
                k = i+1;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            int newIdx = (i - k + n) % n;

            if(newIdx == 0) return nums[i];
        }

        return 0;
    }
};
