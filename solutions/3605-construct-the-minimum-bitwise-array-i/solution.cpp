class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = bitwiseOR(nums[i]);
        }

        return ans;
     
    }

    int bitwiseOR(int n) {

        for(int i = 1; i < n; i++) {
            if((i | (i+1)) == n) return i;
        }

        return -1;
    }
};
