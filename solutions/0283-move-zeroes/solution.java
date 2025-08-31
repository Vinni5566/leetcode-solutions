class Solution {
    public void moveZeroes(int[] nums) {

        //move all non-zero elements to the front
        int k = 0;

        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != 0) {
                nums[k] = nums[i];
                k++;
            }
        }

        //fill the remaining positions with zeroes
        for(int i = k; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}
