class Solution {
public:
    int minOperations(string s) {

        int l = s.length();

        //case 1 : string start from '0'
        int ops1 = 0;

        for(int i = 0; i < l; i++) {

            if(i%2 == 0) {
                if(s[i] == '1') ops1++;
            } else {
                if(s[i] == '0') ops1++;
            }

        }

        //case 2 : string start from '1'
        int ops2 = 0;

        for(int i = 0; i < l; i++) {

            if(i%2 == 0) {
                if(s[i] == '0') ops2++;
            } else {
                if(s[i] == '1') ops2++;
            }

        }

        int minOps = min(ops1, ops2);

        return minOps;
        
    }
};
