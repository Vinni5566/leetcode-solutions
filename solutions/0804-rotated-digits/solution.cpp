class Solution {
public:
    int rotatedDigits(int n) {

        unordered_map<int, int> mp;

        mp[0] = 0;
        mp[1] = 1;
        mp[8] = 8;
        mp[2] = 5;
        mp[5] = 2;
        mp[6] = 9;
        mp[9] = 6;

        int countOfGoodNumbers = 0;

        for(int i = 1; i <= n; i++) {
            if(isGoodNum(i, mp)) {
                countOfGoodNumbers++;
            }
        }

        return countOfGoodNumbers;
    }

    bool isGoodNum(int x, unordered_map<int, int>& mp) {

        string num = to_string(x);

        string rotated_num = "";

        for(char c : num) {
            if(mp.find(c - '0') == mp.end()) return false;
            rotated_num.push_back((mp[c-'0']) + '0');
        }

        if(num == rotated_num) return false;

        return true;
    }


};
