class Solution {
    public int search(int[] nums, int target) {
        
        int res = -1;

        int l = 0;
        int h = nums.length-1;

        while(l <= h) {
            
            int mid = l + (h-l)/2;

            if(nums[mid] == target) {
                res = mid;
                return res;
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
}
