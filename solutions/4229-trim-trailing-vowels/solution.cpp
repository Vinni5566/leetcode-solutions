class Solution {
public:
    string trimTrailingVowels(string s) {

        int l = s.length();

        for(int i = l-1; i >= 0; i--) {
            if(isVowel(s[i])) {
                s.pop_back();
            } else {
                break;
            }
        }

        return s;
        
    }

    bool isVowel(char c) {

        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
        }
    }
};
