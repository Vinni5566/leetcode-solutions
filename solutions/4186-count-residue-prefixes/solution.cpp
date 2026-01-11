class Solution {
public:
    int residuePrefixes(string s) {

        unordered_map<char, int> mp;
        mp[s[0]]++;

        int count = 1;
        int prefixLen = 1;

        for(int i = 1; i < s.length(); i++) {
            prefixLen += 1;
            mp[s[i]]++;
            
            if(mp.size() == prefixLen%3) {
                count++;
            }
        }

        return count;
        
    }
};
