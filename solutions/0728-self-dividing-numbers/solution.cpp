class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;
        
        for(int i = left; i <= right; i++) {
            if(isSelfDividing(i)) {
                res.push_back(i);
            }
        }

        return res;
    }

    bool isSelfDividing(int n) {

        int org = n;

        while(n > 0) {

            int r = n % 10;
            if(r == 0) return false;
            if(org % r != 0) return false;
            n /= 10;
        }

        return true;
    }
};
