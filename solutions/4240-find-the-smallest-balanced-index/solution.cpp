class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return -1;

        vector<long long> sum(n, 0);
        vector<double> prod(n);
        prod[n-1] = 1;

        for(int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + (long long)nums[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            prod[i] = prod[i+1] * (double)nums[i+1];
        }

        for(int i = 0; i < n; i++) {
            if ((double)sum[i] == prod[i]) {
                return i;
            }
        }

        return -1;   
        
    }
};
