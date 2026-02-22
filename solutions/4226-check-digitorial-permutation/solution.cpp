class Solution {
public:
    bool isDigitorialPermutation(int n) {
        
        //calculating factorials of digits 0-9
        vector<int> factorials(10);
        factorials[0] = 1;
        factorials[1] = 1;

        for(int i = 2; i <= 9; i++) {
            factorials[i] = factorials[i-1]*i;
        }

        //calculating sum of factorials of all digits in n
        int sumOfFactOfAllDigits = calcSumOfFactOfAllDigits(n, factorials);

        //converting both original n and sumOfFactOfAllDigitsto string
        string original = to_string(n);
        string sumStr = to_string(sumOfFactOfAllDigits);

        //return if length is diff
        if(original.length() != sumStr.length()) return false;

        //stores freqs of digits of original num
        unordered_map<char, int> freq;

        for(char c : original) {
            freq[c]++;
        }

        //cheking if any permuatation of digits of n is digitorial
        for(char c : sumStr) {
            if(freq.find(c) != freq.end() && freq[c] > 0) {
                freq[c]--;
            } else {
                return false;
            }
        }

        return true;
    }

    int calcSumOfFactOfAllDigits(int n, vector<int>& factorials) {

        int res = 0;

        int num = n;

        while(num > 0) {
            int r = num % 10;
            res += factorials[r];
            num /= 10;
        }

        return res;
    }
};
