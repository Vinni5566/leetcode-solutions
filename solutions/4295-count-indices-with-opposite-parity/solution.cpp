class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        int n = nums.size();

        if(n == 0) return {0};

        vector<int> res(n, 0);

        res[n-1] = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(i < j && ((nums[i] % 2 == 0 && nums[j] % 2 != 0) || (nums[i] % 2 != 0 && nums[j] % 2 == 0))) {
                    res[i]++;
                }
            }
        }

        return res;
    }
};
