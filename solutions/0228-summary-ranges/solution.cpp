class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 0) return {};
        if(n == 1) return {to_string(nums[0])};

        vector<string> res;

        int start = 0;
        int end = 0;

        while(end < n) {

            if (end == n - 1 || nums[end] + 1 != nums[end + 1]) {
                if (start == end) {
                    res.push_back(to_string(nums[start]));
                } else {
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                }

                start = end+1;
            }

            end++;
        }

        return res;
    }
};
