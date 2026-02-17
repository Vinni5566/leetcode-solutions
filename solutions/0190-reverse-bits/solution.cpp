class Solution {
public:
    int reverseBits(int n) {
        
        int res = 0;
        
        for (int i = 0; i < 32; i++) {
            
            // 1. Shift result left to make room for the next bit
            res <<= 1;
            
            // 2. Check if the i-th bit of n is set
            // We use (1 << i) to create a mask for the i-th position
            if (n & (1 << i)) {
                res |= 1;
            }
        }
        
        return res;
    }
};
