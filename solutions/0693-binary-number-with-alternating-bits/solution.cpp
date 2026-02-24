class Solution {
public:
    bool hasAlternatingBits(int n) {

        int prev = n % 2; //keeps track of previous bit
        n /= 2;

        while(n > 0) {
            int r = n % 2;
            n /= 2;

            //if curr_bit == prev_bit, return false
            if(r == prev) return false; 

            prev = r;
        }

        return true;
        
    }
};
