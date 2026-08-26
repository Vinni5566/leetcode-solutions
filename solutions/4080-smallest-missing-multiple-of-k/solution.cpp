class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> set;

        for(int num : nums) set.insert(num);

        for(int i = 1; ; i++) {
            int n = i*k;

            if(!set.contains(n)) return n;
        }

        return 0;
    }
};
