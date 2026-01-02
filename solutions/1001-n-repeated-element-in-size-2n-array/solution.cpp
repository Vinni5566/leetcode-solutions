class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int n = nums.size();

        int maximum = *max_element(nums.begin(), nums.end());

        vector<int> freq(maximum+1, 0);

        for(int num : nums) {
            freq[num]++;
        }

        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] > 1) return i;
        }

        return 0;

    }
};
