class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        int res[] = new int[2];
        res[0] = res[1] = -1;

        for(int i = 0; i < nums.length; i++) {

            if(res[0] == -1 && nums[i] == target) {
                res[0] = i;
            }

            if(nums[i] == target) {
                res[1] = i;
            }
            
            if(res[1] >= 0 && nums[i] != target) break;
        }

        return res;
    }
}
