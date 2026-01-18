class Solution {
public:
    int vowelConsonantScore(string s) {

        int v = 0;   //count of vowels
        int c = 0;   //count of consonants

        for(char ch : s) {

            if(isalpha(ch)) {
                
                //vowel
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    v++;
                    continue;
                }
                
                //consonant
                c++;
                
            }
        }

        if(c > 0) return v/c;

        return 0;
        
    }
};
