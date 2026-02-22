class Solution {
public:
    string maximumXor(string s, string t) {

        int countZero = count(t.begin(), t.end(), '0');
        int countOne = t.length() - countZero;

        string rearranged_t = "";
        string res = ""; 

        //rearranging t to achieve max value of xor of s and t
        for(char c : s) {

            if(c == '1') {
                if(countZero > 0) {
                    rearranged_t += '0';
                    res += '1';
                    countZero--;
                } else {
                    rearranged_t += ('1');
                    res += '0';
                    countOne--;
                }
            } else {
                if(countOne > 0) {
                    rearranged_t += '1';
                    res += '1';
                    countOne--;
                } else {
                    rearranged_t += '0';
                    res += '0';
                    countZero--;
                }
            }
        }

        //maximum integer value obtainable by taking the bitwise XOR of s and rearranged t
        return res;     
    }
};
