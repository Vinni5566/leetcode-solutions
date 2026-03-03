class Solution {
public:
    char findKthBit(int n, int k) {

        if(k == 1) return '0';

        string num = "0";

        while(n--) {

            string rev = invert(num);
            reverse(rev.begin(), rev.end());
            num = num + '1' + rev;
             
        }

        char res = ' ';

        for(char c : num) {
            if(k == 1) {
                res = c;
                break;
            }
            k--;

        }

        return res;
        
    }

    string invert(string s) {

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }

        return s;
    }
};
