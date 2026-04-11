class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        
        int n = nums.size();

        int count = 0;

        for(int num : nums) {

            while(num > 0) {
                int r = num % 10;
                if(r == digit) count++;
                num /= 10;
            }
        }

        return count;
    }
};
