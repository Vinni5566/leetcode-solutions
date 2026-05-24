class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char> set;

        for(char c : password) set.insert(c);

        int score = 0;

        for(auto& c : set) {
            score += points(c);
        }

        return score;
        
    }

    int points(char c) {

        if('a' <= c && c <= 'z') return 1;
        else if('A' <= c && c <= 'Z') return 2;
        else if(c-'0' >= 0 && c-'0' <= 9) return 3;


        return 5;
    }
};
