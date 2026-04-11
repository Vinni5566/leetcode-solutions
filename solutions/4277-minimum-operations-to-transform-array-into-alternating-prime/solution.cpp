class Solution {
public:
    int minOperations(vector<int>& nums) {

        int minOps = 0;
        
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                while(!isPrime(nums[i])) {
                    nums[i]++;
                    minOps++;
                }
            } else {
                while(isPrime(nums[i])) {
                    nums[i]++;
                    minOps++;
                }
            }
        }

        return minOps;
    }

    bool isPrime(int x) {

        if(x == 1) return false;
        if(x == 2 || x == 3) return true;

        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) return false;
        }

        return true;
    }
};
