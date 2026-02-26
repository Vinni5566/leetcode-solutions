class Solution {
public:
    int numSteps(string s) {

        int l = s.length();

        if(l == 1) {
            if(s[0] == '1') return 0;
            else return 1;
        }

        if(s == "10") return 1;

        int steps = 0;
        int carry = 0;
        
        for(int i = l-1; i >= 0; i--) {

            if(carry == 1) {
                if(s[i] == '1') {
                    s[i] = '0';
                } else {
                    s[i] = '1';
                    carry = 0;
                }
            }

            if(s[i] == '1') {
                if(i == 0) return steps;

                carry = 1;
                steps += 2;
            } else {
                steps+=1;
            }
        }

        return steps;
        
    }
};
