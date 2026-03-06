class Solution {
public:
    bool checkOnesSegment(string s) {

        int l = s.length();

        if(l == 1) {
            if(s[0] == '1') return true;
            else return false;
        }

        int countSegments = 0;

        if(s[0] == '1') countSegments++;

        for(int i = 0; i < l-1; i++) {
            if(s[i] == '0' && s[i+1] == '1') countSegments++;
        }

        if(countSegments == 1) return true;

        return false;
        
    }
};
