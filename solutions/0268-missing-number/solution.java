class Solution {
    public int missingNumber(int[] nums) {

        Arrays.sort(nums);

        int res = 0;

        for(int i =0; i < nums.length; i++) {
            if(nums[i] != res ) return res;

            res++;
        }

        return res;
        
    }
}
