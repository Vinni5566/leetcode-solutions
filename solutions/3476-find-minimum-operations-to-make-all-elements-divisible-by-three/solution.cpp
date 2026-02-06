class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n = nums.size();

        int minOps = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 3 != 0) {
                minOps += min(nums[i]%3, 3-(nums[i]%3));
            }
        }

        return minOps;
        
    }
};
