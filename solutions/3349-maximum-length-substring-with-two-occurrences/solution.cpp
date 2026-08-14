class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        unordered_map<char, int> mp;

        int l = s.length();

        int len = 0;

        int i = 0;

        for(int j = 0; j < l; j++) {

            mp[s[j]] += 1;

            for(int idx = i; idx <= j; idx++) {
                while (mp[s[j]] > 2) {
                    mp[s[i]]--;
                    i++;
                }
            }

            len = max(len, j-i+1);

        }

        return len;
    }
};
