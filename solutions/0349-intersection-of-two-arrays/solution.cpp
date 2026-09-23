class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set1;

        for(int num : nums1) set1.insert(num);

        unordered_set<int> set2;

        for(int num : nums2) {
            if(set1.contains(num)) set2.insert(num);
        }

        vector<int> res;

        for(int ele : set2) res.push_back(ele);

        return res;
    }
};
