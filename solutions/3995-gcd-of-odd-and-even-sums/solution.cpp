class Solution {
public:

    int gcd(int a, int b) {

        if(b == 0) return a;

        return gcd(b, a%b);
    }

    int gcdOfOddEvenSums(int n) {
        
        int odd_sum = 0;
        int even_sum = 0;

        int k = n;

        for(int i = 1; ; i+=2) {
            if(k == 0) break;

            odd_sum += i;
            k--;
        }

        k = n;

        for(int i = 0; ; i+=2) {
            if(k == 0) break;

            even_sum += i;
            k--;
        }

        return gcd(odd_sum, even_sum);

    }
};
