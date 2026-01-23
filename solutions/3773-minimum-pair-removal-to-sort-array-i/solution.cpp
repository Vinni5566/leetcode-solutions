class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int n = nums.size();
        
        int minOps = 0;

        while(!is_sorted(nums.begin(), nums.end())) {

            int index = minPairSum(nums);

            nums[index] = nums[index] + nums[index+1];

            nums.erase(nums.begin() + index + 1);

            minOps++;
        }

        return minOps;
        
    }

    int minPairSum(vector<int>& nums) {

        int idx = -1;
        int minSum = INT_MAX;

        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] + nums[i+1] < minSum) {
                minSum = nums[i] + nums[i+1];
                idx = i;
            }
        }

        return idx;
    }
};
