class Solution {
public:
    int reverseDegree(string s) {
        
        int res = 0;

        for(int i = 0; i < s.length(); i++) {

            char c = s[i];

            int pos = 26 - (c-'a');

            res += (pos * (i+1));
        }

        return res;
    }
};
