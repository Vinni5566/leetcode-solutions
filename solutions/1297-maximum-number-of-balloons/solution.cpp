class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> mp;
        mp['b'] = 0;
        mp['a'] = 0;
        mp['l'] = 0;
        mp['o'] = 0;
        mp['n'] = 0;

        for(char c : text) {
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                mp[c]++;
            }
        }

        mp['l'] /= 2;
        mp['o'] /= 2;

        int res = INT_MAX;

        for(auto& p : mp) {
            res = min(res, p.second);
        }

        return res;
    }
};
