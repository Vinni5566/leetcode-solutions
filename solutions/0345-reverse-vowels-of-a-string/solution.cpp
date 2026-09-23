class Solution {
public:

    bool isVowel(char c) {

        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') return true;

        return false;
    }

    string reverseVowels(string s) {
        
        int n = s.length();

        int i = 0;
        int j = n-1;

        while(i < j) {

            if(!isVowel(s[i])) i++;
            if(!isVowel(s[j])) j--;

            if(isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};
