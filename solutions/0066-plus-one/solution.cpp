class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        int increment = digits[n-1] + 1;
        
        digits[n-1] = increment % 10;

        int carry = increment/10;

        int i = n-2;

        while(carry > 0 && i >= 0) {

            int sum = digits[i] + carry;

            digits[i] = sum % 10;

            carry = sum/10;

            i--;
        }

        if(carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
