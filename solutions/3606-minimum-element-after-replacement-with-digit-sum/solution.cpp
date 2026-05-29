class Solution {
public:
    int minElement(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            string num = to_string(nums[i]);
            nums[i] -= nums[i];
            for(char c : num) {
                nums[i] += c-'0';
            }
        }
        
        return *min_element(nums.begin(), nums.end());
        
    }
};
