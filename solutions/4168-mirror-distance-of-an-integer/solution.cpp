class Solution {
public:
    int mirrorDistance(int n) {
        
        int original = n;  //original number
 
        int reversed = 0;  //reversed number

        while(n > 0) {
            int r = n%10;
            reversed = (reversed*10) + r;
            n /= 10;
        }

        return abs(original - reversed);  //mirror distance
    }
};
