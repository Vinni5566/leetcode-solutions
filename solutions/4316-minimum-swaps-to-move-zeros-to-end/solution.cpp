class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

        int n = nums.size();

        int ops = 0;

        int i = 0;
        int j = n-1;

        while(i < j) {

            while(i < j && nums[i] != 0) i++;
            while(i < j && nums[j] == 0) j--;

            if(nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                ops++;
                i++;
                j--;
            }
        }

        return ops;
    }
};
