class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();

        //base case
        if(n < 3) return false;

        if(n == 3) {
            for(int i = 0; i < 2; i++) {
                if(nums[i] >= nums[i+1]) return false;
            }

            return true;
        }

        //check if all elements are same
        bool allSame = true;

        for(int i = 0; i < n-1; i++) {
            if(nums[i] != nums[i+1]) {
                allSame = false;
                break;
            }
        }

        if(allSame) return false;

        //check if nums is in descending order
        bool inDescendingOrder = true;

        for(int i = 0; i < n-1; i++) {
            if(nums[i] < nums[i+1]) {
                inDescendingOrder = false;
                break;
            }
        }

        if(inDescendingOrder) return false;

        //normal case

        int firstEle = INT_MAX;
        int secondEle = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= firstEle) {
                firstEle = nums[i];
            } else if(nums[i] <= secondEle) {
                secondEle = nums[i]; 
            } else {
                return true;
            }
        }

        return false;
   
    }
};
