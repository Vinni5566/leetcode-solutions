class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n == 0) return false;

        long long num = n;
        if((num & num-1) != 0) return false;

        return true;
    }
};
