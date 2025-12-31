class Solution {
public:
    long long maximumScore(vector<int>& nums) {

        int n = nums.size();

        long long prefixSum = 0;
        vector<long long> suffixMin(n);
        suffixMin[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i+1], (long long)nums[i]);
        }

        long long maxScore = INT_MIN;

        for(int i = 0; i < n-1; i++) {
            prefixSum += nums[i];

            long long currScore = prefixSum - suffixMin[i+1];

            maxScore = max(maxScore, currScore);
        }

        return maxScore;
        
    }

};
