class Solution {

public:
    vector<int> separateDigits(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            
            string num = to_string(nums[i]);

            for(char c : num) {
                ans.push_back(c-'0');
            }
        }

        return ans;
        
    }
};
