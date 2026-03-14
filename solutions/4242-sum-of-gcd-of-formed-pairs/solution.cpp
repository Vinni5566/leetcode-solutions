class Solution {
public:

    long long calculateGcd(long long a, long long b) {

        while(b != 0) {
            long long r = a%b;
            a  = b;
            b = r;
        }

        return a;
    }
    
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> mx(n);
        mx[0] = nums[0];

        for(int i = 1; i < n; i++) {

            mx[i] = max(nums[i], mx[i-1]);
        }

        vector<long long> prefixGcd(n);

        for(int i = 0; i < n; i++) {
            prefixGcd[i] = calculateGcd(nums[i], mx[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0;
        int j = n-1;

        long long sum = 0;

        while(i < j) {
            sum += calculateGcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return sum;
        
        
    }
};
