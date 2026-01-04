class Solution {
public:
    string largestEven(string s) {
        
        for(int i = s.length()-1; i >= 0; i--) {
            if((s[i]-'0') % 2 == 0) break;
            s.pop_back(); //break if last digit is odd
        }

        return s;  //largest even integer
    }
};
