class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set;

        for(int num : nums1) set.insert(num);

        int cmn_mn = INT_MAX;

        for(int num : nums2) {
            if(set.contains(num)) {
                cmn_mn = min(cmn_mn, num);
            }
        }

        if(cmn_mn == INT_MAX) return -1;

        return cmn_mn;
    }
};
