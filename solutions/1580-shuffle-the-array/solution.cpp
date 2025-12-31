class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> result(2*n);

        int i = 0;
        int j = 0+n;

        for(int k = 0; k < 2*n; k+=2) {
            result[k] = nums[i];
            result[k+1] = nums[j];
            i++;
            j++;
        }

        return result;
    }
};
