class Solution {
public:
    int countBinarySubstrings(string s) {

        int l = s.length();

        if(l == 1) return 0;

        vector<int> groups;

        int currGroupSize = 1;

        for(int i = 0; i < l-1; i++) {

            if(s[i] == s[i+1]) {
                currGroupSize += 1;
            } else {
                groups.push_back(currGroupSize);
                currGroupSize = 1;
            }
        }

        if(s[l-2] == s[l-1]) {
            groups.push_back(currGroupSize);
        } else {
            groups.push_back(1);
        }

        int count = 0;

        for(int i = 1; i < groups.size(); i++) {
            count += min(groups[i-1], groups[i]);
        }
        
        return count;    
        
    }
};
