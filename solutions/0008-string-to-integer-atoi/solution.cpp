class Solution {
public:
    int myAtoi(string s) {
        
        long long result = 0;
        bool negative = false;

        for(int i = 0; i < s.length(); i++) {

            //skip leading spaces
            if(s[i] == ' ') {
                if(i != 0 &&s[i-1] != ' ') break; // space after starting number/sign
                continue;
            }

            // handle sign
            if(s[i] == '-' || s[i] == '+') {

                if(i != 0 && s[i-1] != ' ') break; //sign in between
                negative = (s[i] == '-');
                continue;
      
            }


            //check if s[i] is didgit
            if(isdigit(s[i])) {
                int num = s[i]-'0';

                //if overflow break
                if(result > LLONG_MAX/10 || result == LLONG_MAX/10 && num > LLONG_MAX%10) {
                    break;
                } 
                result = (result*10) + num;
                       
            } else {
                break;
            }

        }

        //if negative
        if(negative) {
            result = result*(-1);
        }

        //clamp to int range
        if(result < INT_MIN) return INT_MIN;
        if(result > INT_MAX) return INT_MAX;

        return (int)result;
    }
};
