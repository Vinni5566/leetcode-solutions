class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> result;

        int posIndex = 0;
        int negIndex = 0;

        while (posIndex < n && negIndex < n) {

            if (nums[posIndex] < 0) posIndex++;
            if (nums[negIndex] > 0) negIndex++;

            if (posIndex < n && negIndex < n &&
                nums[posIndex] > 0 && nums[negIndex] < 0) {

                result.push_back(nums[posIndex]);
                result.push_back(nums[negIndex]);

                posIndex++;
                negIndex++;
            }
        }

        return result;
    }
};
