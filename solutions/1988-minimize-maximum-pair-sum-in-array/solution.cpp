class Solution {
public:
    int minPairSum(vector<int>& nums) {

        int n = nums.size();
        
        int minMaxPairSum = 0;

        sort(nums.begin(), nums.end());

        int i = 0; 
        int j = n-1;

        while(i < j) {

            int currsum = nums[i] + nums[j];

            minMaxPairSum = max(minMaxPairSum, currsum);

            i++;
            j--;
        }

        return minMaxPairSum;
    }
};
