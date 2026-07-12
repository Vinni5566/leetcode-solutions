class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {

        int mod = 1e9 + 7;

        int n = nums.size();

        long long ops_cnt = 0;

        long long curr_resources = k;

        for(int i = 0; i < n; i++) {
            
            if(curr_resources < nums[i]) {
                long long diff = nums[i]-curr_resources;

                long long  ops_needed = diff/k;

                if(diff%k != 0) {
                    ops_needed += 1;
                }

                curr_resources += (ops_needed*k);
                ops_cnt += ops_needed;
            }

            curr_resources -= nums[i];
        }

        
        long long a = ops_cnt;
        long long b = ops_cnt+1;

        if(a % 2 == 0) a/=2;
        else b/=2;

        long long cost = ((a%mod)*(b%mod))%mod;

        return cost;
        
    }
};
