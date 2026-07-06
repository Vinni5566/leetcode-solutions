class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        
        int n = nums.size();

        int res = 0;

        unordered_map<int, vector<int>> mp;

        int maxDigitRange = 0;

        for(int i = 0; i < n; i++) {
            string num = to_string(nums[i]);

            int mx = 0;
            int mn = 9;

            for(char c : num) {
                int digit = c-'0';

                mx = max(mx, digit);
                mn = min(mn, digit);
            }

            maxDigitRange = max(maxDigitRange, mx-mn);

            mp[mx-mn].push_back(nums[i]);
        }

        for(auto& p : mp) {
            if(p.first == maxDigitRange) {

                for(int num : p.second) {
                    res += num;
                }
            }
        }

        return res;
    }
};
