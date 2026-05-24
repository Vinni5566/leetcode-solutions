class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        int n = nums.size();

        int count = 1;

        vector<bool> flag(n, 0);

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                if(count == k) {
                    flag[i] = 1;
                }
                else {
                    count++;
                }
            } else {
                count = 1;
            }
        }

        for(int i = 0; i < n; i++) {
            if(flag[i] == 1) {
                nums[i]=0;
            }
        }

        sort(nums.begin(), nums.end(), greater<int>());

        while(nums[nums.size()-1] == 0) {
            nums.pop_back();
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};
