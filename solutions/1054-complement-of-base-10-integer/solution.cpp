class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;
        if(n == 1) return 0;

        string s = "";

        while(n>0) {
            s += to_string(n%2);
            n /= 2;
        }

        reverse(s.begin(), s.end());

        for(char &c : s) {
            c ^= 1;
        }

        return stoi(s, nullptr, 2);
        
    }
};
