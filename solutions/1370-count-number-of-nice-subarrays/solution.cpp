class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        if(nums.size() < k) return 0;

        return atMost(k, nums) - atMost(k-1, nums);


    }

    int atMost(int k, vector<int>& nums) {
        int l = 0;
        int count = 0;
        int odd = 0;

        for(int r = 0; r < nums.size(); r++) {
            
            if(nums[r] % 2 != 0) odd++;

            while(odd > k) {
                if (nums[l] % 2 != 0) odd--;
                l++;
            }

            count += (r-l+1);
        }

        return count;
    }
};
