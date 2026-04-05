class Solution {
public:
    bool judgeCircle(string moves) {

        unordered_map<char, int> mp;
        mp['U'] = 0;
        mp['D'] = 0;
        mp['R'] = 0;
        mp['L'] = 0;

        for(char c : moves) {
            mp[c]++;
        }

        if(mp['U'] != mp['D'] || mp['R'] != mp['L']) return false;

        return true;
        
    }
};
