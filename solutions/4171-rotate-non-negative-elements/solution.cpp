class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        vector<int> positive;

        for(int num : nums) {
            if(num >= 0) positive.push_back(num);
        }

        int n = positive.size();

        if(n == 0) return nums;

        k %= n;

        vector<int> rotatedPositive(n);

        for(int i = 0; i < n; i++) {
            int newIdx = (i-k+n) % n;
            rotatedPositive[newIdx] = positive[i];
        }

        int j = 0;
        int i = 0;

        while(i < nums.size() && j < n) {
            if(nums[i] >= 0) {
                nums[i] = rotatedPositive[j];
                j++;
            }

            i++;
        }

        return nums;
    }
};
