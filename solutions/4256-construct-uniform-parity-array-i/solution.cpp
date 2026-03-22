class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();

        int count_eve = 0;
        int count_odd = 0;

        for(int num:nums1){
            if(num%2 == 0) count_eve++;
            else count_odd++;
        }

        if(count_eve > 0 || count_odd >= 2) return true;
        if(count_odd > 0 || count_eve > 0) return true;

        return false;
        
    }
};
