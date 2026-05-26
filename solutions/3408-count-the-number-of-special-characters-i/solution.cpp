class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int l = word.length();

        unordered_set<char> lowerCase;
        unordered_set<char> upperCase;

        int count = 0;

        for(char c : word) {
            if(islower(c)) lowerCase.insert(c);
            if(isupper(c)) upperCase.insert(c);
        }

        for(auto& c : lowerCase) {
            if(upperCase.contains(toupper(c))) count++;
        }

        return count;

    }
};
