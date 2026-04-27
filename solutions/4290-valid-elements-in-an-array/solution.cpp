class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        
        int n = nums.size();

        if (n <= 1) return nums;

        vector<bool> isValid(n, false);

        isValid[0] = true;
        isValid[n - 1] = true;

        int leftMax = nums[0];

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > leftMax) {
                isValid[i] = true;
            }

            leftMax = max(leftMax, nums[i]); 
        }

        int rightMax = nums[n - 1];

        for (int i = n - 2; i > 0; i--) {
            if (nums[i] > rightMax) {
                isValid[i] = true;
            }

            rightMax = max(rightMax, nums[i]);
        }

        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (isValid[i]) res.push_back(nums[i]);
        }
        
        return res;
        
    }
};
