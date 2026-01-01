class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        
        int n = nums.size();

        //base case
        if(n == 1) return 0;

        sort(nums.begin(), nums.end());  //sort the array

        int maxKSum = 0;
        int minKSum = 0;

        //sum k smallest
        for(int i = 0; i < k; i++) {
            minKSum += nums[i];
        }

        //sum k largest
        for(int i = n-1; i >= n-k; i--) {
            maxKSum += nums[i];
        }

        return abs(maxKSum - minKSum);
    }
};
