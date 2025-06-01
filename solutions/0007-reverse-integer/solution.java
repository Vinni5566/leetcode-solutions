class Solution {
    public int reverse(int x) {
        int res = 0;

        while(x != 0) {
            int n = x%10;

            // positive overflow
            if(res > Integer.MAX_VALUE/10 || (res == Integer.MAX_VALUE/10 && n > 7)) return 0;

            // negative overflow
            if(res < Integer.MIN_VALUE/10 || (res == Integer.MIN_VALUE/10 && n < -8)) return 0;

            res = (res*10) + n ;
            x /= 10;
        }

        return res;        
    }
}
