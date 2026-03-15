class Solution {
public:
    int countCommas(int n) {

        if(n < 1000) return 0;

        if(n <= 9999) {
            return n-1000+1;
        }

        if(n <= 99999) {
            return 9000+(n-10000+1);
        }

        if(n == 100000) {
            return 9000 + 90000 + 1;
        }

        return 0;
        
    }
};
