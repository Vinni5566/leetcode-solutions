class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();

        vector<int> smaller;
        vector<int> larger;
        vector<int> equal;

        for(int num : nums) {
            if(num < pivot) {
                smaller.push_back(num);
            } else if(num > pivot) {
                larger.push_back(num);
            } else {
                equal.push_back(num);
            }
        }

        vector<int> res = smaller;

        for(int x : equal) res.push_back(x);
        for(int x : larger) res.push_back(x);

        return res;

    }
};
