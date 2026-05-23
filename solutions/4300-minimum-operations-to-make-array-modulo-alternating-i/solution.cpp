class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> even(k, 0), odd(k,0); //cost

        for(int i = 0; i < n; i++) {
            int r = nums[i]%k;

            for(int t = 0; t < k; t++) {
                int d = abs(r-t);
                int cost = min(d, k-d);

                if(i % 2 == 0) {
                    even[t] += cost;
                } else {
                    odd[t] += cost;
                }
            }
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(i == j) continue;

                long long curr = even[i]+odd[j];
                ans = min(ans, curr);
            }
        }

        return (int)ans;
    }
};
