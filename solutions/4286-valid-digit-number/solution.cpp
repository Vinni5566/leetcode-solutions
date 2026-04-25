class Solution {
public:
    bool validDigit(int n, int x) {
        
        string num = to_string(n);
        char c = x + '0';

        if(num[0] == c || num.find(c) == -1) return false;

        return true;

    }
};
