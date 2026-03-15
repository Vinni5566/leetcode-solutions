class Solution {
public:
    long long countCommas(long long n) {

        //0 commas
        if(n < 1000) return 0;

        // 1 COMMA RANGE (4-6 digits)
        if(n <= 9999)    return (n - 1000 + 1);
        if(n <= 99999)   return 9000 + (n - 10000 + 1);
        if(n <= 999999)  return 99000 + (n - 100000 + 1);

        // 2 COMMA RANGE (7-9 digits) - Use multiplier * 2
        if(n <= 9999999)   return 999000 + (n - 1000000 + 1) * 2;
        if(n <= 99999999)  return 18999000 + (n - 10000000 + 1) * 2;
        if(n <= 999999999) return 198999000 + (n - 100000000 + 1) * 2;

        // 3 COMMA RANGE (10-12 digits) - Use multiplier * 3
        if(n <= 9999999999LL)    return 1998999000 + (n - 1000000000LL + 1) * 3;
        if(n <= 99999999999LL)   return 28998999000LL + (n - 10000000000LL + 1) * 3;
        if(n <= 999999999999LL)  return 298998999000LL + (n - 100000000000LL + 1) * 3;

        // 4 COMMA RANGE (13-15 digits) - Use multiplier * 4
        if(n <= 9999999999999LL)   return 2998998999000LL + (n - 1000000000000LL + 1) * 4;
        if(n <= 99999999999999LL)  return 38998998999000LL + (n - 10000000000000LL + 1) * 4;
        if(n <= 999999999999999LL) return 398998998999000LL + (n - 100000000000000LL + 1) * 4;

        // Exactly 10^15 (5 commas)
        if(n == 1000000000000000LL) {
            return 3998998998999000LL + 5;
        }

        return 0;
        
    }
};
