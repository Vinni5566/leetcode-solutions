class Solution {
public:
    string reverseByType(string s) {

        int n = s.length();

        if(n == 1) return s;

        string letters = "";
        string specialChars = "";

        for(char ch : s) {
            if(isalpha(ch)) {
                letters.push_back(ch);
            } else {
                specialChars.push_back(ch);
            }
        }

        reverse(letters.begin(), letters.end());
        reverse(specialChars.begin(), specialChars.end());

        string res = "";

        int i = 0;
        int j = 0;

        for(char ch : s) {
            if(isalpha(ch)) {
                res.push_back(letters[i]);
                i++;
            } else {
                res.push_back(specialChars[j]);
                j++;
            }
        }

        return res;
        
    }
};
