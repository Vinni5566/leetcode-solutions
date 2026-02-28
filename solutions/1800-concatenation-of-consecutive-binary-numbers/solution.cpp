class Solution {
public:
    int concatenatedBinary(int n) {

        int MOD = 1e9 + 7;

        long long res = 1;

        for(int i = 2; i <= n; i++) {

            //count no. of bits in i 
            //total bits - num of leading zeros
            int width = 32 - __builtin_clz(i);  

            //shift res by width and add i, which works same as concatenating binary strings
            res = ((res<<width) + i) % MOD;
        }

        return res;
  
    }
};
