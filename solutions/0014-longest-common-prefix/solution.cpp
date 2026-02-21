class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();

        if(n == 1) return strs[0];

        int minLen = strs[0].length();

        for(string str : strs) {
            minLen = min(minLen, (int)str.length());
        }
        
        string res = "";

        for(int i = 0; i < minLen; i++) {

            for(int j = 0; j < n-1; j++) {
                if(strs[j][i] != strs[j+1][i]) {
                    return res;
                }
            }

            res.push_back(strs[0][i]);
        }

        return res;
    }
};
