class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int n = nums.size();

        if(n == 1) return 0;

        sort(nums.begin(), nums.end());

        int windowSize = 1;

        int i = 0;
        int j = i+1;
        
        while(i < n) {
            while(j < n && (long long)nums[j] <= (long long)nums[i]*k) {
                j++;
            }

            windowSize = max(windowSize, j-i);
            i++;
        }

        return n-windowSize;

        
    }
};
