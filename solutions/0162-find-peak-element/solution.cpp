class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        //base case
        if(n == 1) return 0;

        //handle boundary peaks explicitly
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int l = 0;
        int r = n-1;

        //binary serach using slope comparison
        while(l < r) {
            int mid = l + (r-l)/2;

            //slope increasing, peak must be on right
            if(nums[mid] < nums[mid+1]) {
                l = mid + 1;
            } 
            
            //slope decreasing, peak must be on left
            else {
                r = mid;
            }
        }
        
        //l == r, peak index
        return l;
    }
};
