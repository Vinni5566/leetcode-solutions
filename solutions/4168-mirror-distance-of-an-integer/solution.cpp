class Solution {
public:
    int mirrorDistance(int n) {
        
        if(1 <= n && n <= 9) return 0;

        int original = n;
        int reverse = 0;

        while(n > 0) {
            int r = n%10;
            n /= 10;
            reverse = (reverse*10) + r;
        }

        return abs(original - reverse);
    }
};
