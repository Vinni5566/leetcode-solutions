class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(k == 1) return 0;

        if(k == n) {
            return *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        }

        int minDiff = INT_MAX;

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = i+k-1;

        while(j < n) {

            minDiff = min(minDiff, nums[j]- nums[i]);
            i++;
            j++;
        }

        return minDiff;


    }
};
