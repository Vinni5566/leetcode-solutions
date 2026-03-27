class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            int rem = sum % k;

            if(mp.find(rem) != mp.end()) {
                if(i - mp[rem] >= 2) return true;
            } else {
                mp[rem] = i;
            }
        }

        return false;
    }
};
