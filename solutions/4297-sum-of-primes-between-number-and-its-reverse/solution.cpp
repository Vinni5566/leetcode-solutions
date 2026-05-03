class Solution {
public:
    int sumOfPrimesInRange(int n) {

        int rev_n = reverse(n);

        int res = 0;

        for(int i = min(n, rev_n); i <= max(n,rev_n); i++) {
            if(isPrime(i)) {
                res += i;
            }
        }

        return res;
    }

    int reverse(int n) {
        int rev = 0;

        while(n > 0) {
            int r = n % 10;

            rev = rev*10 + r;

            n /= 10;
        }

        return rev;
    }

    bool isPrime(int n) {

        if(n == 1) return false;
        if(n == 2) return true;

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }

        return true;
    }
};
