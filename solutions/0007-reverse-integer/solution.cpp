class Solution {
public:
    int reverse(int x) {

        bool isNeg = x < 0;
        
        long long n = abs((long long)x);
        long long rev = 0;
        
        while(n > 0) {
            int r = n % 10;
            rev = rev * 10 + r;
            n /= 10;
            
            if(rev > INT_MAX) return 0;
        }
        
        return isNeg ? -rev : rev;
    }
};
