class Solution {
    public int removeDuplicates(int[] nums) {
        int k=0;
        for(int i=0;i<nums.length;i++) {
            if(i==0) {
                nums[k]=nums[i];
                k++;
            } else if(nums[i]!=nums[i-1] && i!=0) {
                nums[k]=nums[i];
                k++;
            } else {
                continue;
            }
        }
        return k;
    }
}
