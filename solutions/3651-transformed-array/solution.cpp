class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums;

        vector<int> res(n);

        for(int i = 0; i < n; i++) {

            if(nums[i] == 0) {
                res[i] = nums[i];
            } else {
                int idx = (nums[i] + i) % n;
                if(idx < 0) idx += n;
                res[i] = nums[idx];
            }
        }

        return res;
        
    }
};
