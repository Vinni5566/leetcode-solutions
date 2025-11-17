class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = s.length();

        if(l == 0 || l == 1) return l;

        int i = 0;
        int j = 0;

        unordered_set<char> set;
        int maxLen = 0;

        while(j < l) {

            char ch = s[j];

            if(set.find(ch) != set.end()) {
                maxLen = max(maxLen, static_cast<int>(set.size()));
                set.erase(s[i]);
                i++;
            } else {
                set.insert(ch);
                j++;
            }
        }

        maxLen = max(maxLen, static_cast<int>(set.size()));

        return maxLen;
    }
};
