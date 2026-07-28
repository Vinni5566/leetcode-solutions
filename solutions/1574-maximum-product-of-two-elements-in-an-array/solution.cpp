class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int maxProd = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                maxProd = max(maxProd, (nums[i]-1)*(nums[j]-1));
            }
        }

        return maxProd;
    }
};
