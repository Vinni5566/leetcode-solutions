class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return;  //base case

        int pivotIdx = -1;

        //finding pivot index: where nums[i] < nums[i+1]
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivotIdx = i;
                break;
            }
        }

        //if no pivot index means nums is decreasing the sort nums in decreasing order ad return
        if(pivotIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //find smallest greater ele in suffix and swap with pivot ele
        for(int i = n-1; i > pivotIdx; i--) {
            if(nums[i] > nums[pivotIdx]) {
                swap(nums[i], nums[pivotIdx]);
                break;
            }
        }


        //reverse to get next lexicographically greater permutation as suffix is in decreasing order now which is not next lexicographically greater permutation, it is the largest arrangement of suffix
        reverse(nums.begin()+pivotIdx+1, nums.end());

        return;     
        
    }
};
