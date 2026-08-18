class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        if(k > nums.size()) return -1;

        if(k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }

        int i = 0;

        for(int j = k-1; j < nums.size(); j++) {
            for(int idx = i; idx <= j; idx++) {
                mp[nums[idx]]++;
            }

            i++;
        }

        int mx = -1;

        for(auto& p : mp) {
            if(p.second == 1) {
                mx = max(mx, p.first);
            }
        }

        return mx;

    }
};
