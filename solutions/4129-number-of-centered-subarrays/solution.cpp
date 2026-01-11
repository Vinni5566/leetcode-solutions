class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {

        int n = nums.size();
        
        int count = 0;

        vector<int> prefixSum(n+1, 0);
        
        for(int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            for(int j = i; j < n; j++) {
                freq[nums[j]]++;
                int subArrSum = prefixSum[j+1] - prefixSum[i];
                if(freq[subArrSum] > 0) count++;
            }
        }

        return count;
        
    }
};
