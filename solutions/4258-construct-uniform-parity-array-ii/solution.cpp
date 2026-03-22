class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();

        int even = 0;
        int odd = 0;

        for(int num : nums1) {
            if(num%2==0) even++;
            else odd++;
        }

        if((even > 0 && odd == 0) || (even == 0 && odd > 0)) return true;

        sort(nums1.begin(), nums1.end());

        //all odd
        bool seen_smaller_odd = false;

        for(int num : nums1) {
            if(!seen_smaller_odd && num%2==0) {
                return false;
            } else {
                if(num%2!=0) {
                    seen_smaller_odd = true;
                    return true;
                }
            }
        }

        return false;

        
        
        
    }
};
