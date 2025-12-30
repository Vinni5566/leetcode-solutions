class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;  //min divisor
        int high = *max_element(nums.begin(), nums.end()); //max divisor

        while(low < high) {

            int mid = low + (high - low)/2;

            int sum = 0;

            for(int num : nums) {
                sum += (num + mid - 1)/mid;
            }

            //if curr divisor feasible, try smaller divisor
            if(sum <= threshold) {
                high = mid;
            } 
            
            //try a larger divisor
            else {
                low = mid + 1;
            }
        }

        //min feasible divisor
        return low;
        
    }
};
