class Solution {
    public int pivotIndex(int[] nums) {

        int totalSum = 0;

        for(int i = 0; i < nums.length; i++) {
            totalSum += nums[i];
        }

        int sumL = 0;

        for(int i = 0; i < nums.length; i++) {
            int sumR = totalSum - sumL - nums[i];
            if(sumL == sumR) return i;
            sumL += nums[i];
        }

        return -1;
    }
}
