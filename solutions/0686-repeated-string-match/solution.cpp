class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string repeated = a;
        
        int count = 1;

        //build until length >= b
        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        //check minimal case
        if (repeated.find(b) != string::npos) {
            return count;
        }

        //add one more for overlap case
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) {
            return count;
        }

        return -1;
        
    }
};
