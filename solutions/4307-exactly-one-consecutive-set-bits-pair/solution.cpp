class Solution {
public:
    bool consecutiveSetBits(int n) {
        
        int pairs = 0;

        while (n > 1) {
            if ((n & 1) && ((n >> 1) & 1))
                pairs++;

            n >>= 1;
        }

        return pairs == 1;
    }
};
