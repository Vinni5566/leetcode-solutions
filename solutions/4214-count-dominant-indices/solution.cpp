class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return 0;

        vector<int> sum(n);
        sum[n-1] = nums[n-1];
        sum[0] = nums[0];

        for(int i = n-2; i >= 0; i--) {
            sum[i] = sum[i+1] + nums[i];
        }

        int countOfDominantIndices = 0;

        for(int i = 0; i < n-1; i++) {
            int avg = sum[i+1]/(n-i-1);
            if(nums[i] > avg) {
                countOfDominantIndices++;
            }
        }

        return countOfDominantIndices;

        
    }
};
