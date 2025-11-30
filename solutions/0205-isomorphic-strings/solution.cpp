class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length() != t.length()) return false;

        unordered_map<char, char> mp;
        unordered_map<char, char> mp1;

        for(int i = 0; i < s.length(); i++) {

            if(mp.count(s[i])) {
                if(mp[s[i]] != t[i]) return false;
                else continue;
            }

            if(mp1.count(t[i])) {
                if(mp1[t[i]] != s[i]) return false;
                else continue;
            }

            mp[s[i]] = t[i];
            mp1[t[i]] = s[i];
        }

        return true;

    }
};
