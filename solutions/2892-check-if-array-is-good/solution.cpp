class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) return false;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            if(i == n-1) {
                if(i != nums[i]) return false;
            } else if(i+1 != nums[i]){
                return false;
            }
        }

        return true;
    }
};
