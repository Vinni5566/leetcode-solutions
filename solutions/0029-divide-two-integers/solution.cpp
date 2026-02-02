class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long long d1 = (long long)dividend;
        long long d2 = (long long)divisor;

        long long res = d1/d2;

        if(res > INT_MAX) return INT_MAX;
        if(res < INT_MIN) return INT_MIN;

        return (int) res;
    }
};
