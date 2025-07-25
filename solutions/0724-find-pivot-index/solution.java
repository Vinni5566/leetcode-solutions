class Solution {
    public int pivotIndex(int[] nums) {

        int res = -1;
        for(int i = 0; i < nums.length; i++) {
            if(calculateSum(i, nums)) {
                res = i;
                return res;
            }
        }

        return res;
        
    }

    public boolean calculateSum(int index, int[] nums) {

        int sumL = 0;
        int sumR = 0;

        for(int i = 0; i < nums.length; i++) {
            if(i < index) {
                sumL += nums[i];
            }

            if(i > index) {
                sumR += nums[i];
            }
        }

        if(sumL == sumR) return true;

        return false;
    }
}
