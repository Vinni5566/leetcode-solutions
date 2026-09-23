class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int l = s.length();
        int n = t.length();

        int i = 0;

        for(int j = 0; j < n; j++) {

            if(i == l) return true;
            if(t[j] == s[i]) i++;
        }

        if(i == l) return true;

        return false;
    }
};
