class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l < r) {

            int mid = l + (r-l)/2;

            if(nums[mid] <= nums[r]) { //min element is in left half
                r = mid;
            } else {  //min element is in right half
                l = mid + 1; 
            }
        }

        // l will point to index of min element
        return nums[l];
    }
};
