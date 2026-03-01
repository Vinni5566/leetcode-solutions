class Solution {
public:
    int minPartitions(string n) {

        int maxDigit = 0;

        //for each digit in n, we need that digit times 1, each one belongs to one deci-binary number

        //so, minimum no. of deci-binary numbers to form n, will be eqaul to largest digit in n

        for(char c : n) {
            maxDigit = max(maxDigit, c-'0');
        }

        return maxDigit;
        
    }
};
