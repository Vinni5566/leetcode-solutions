class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fiveCount = 0;
        int tenCount = 0;

        for(int bill : bills) {
            if(bill == 5) {
                fiveCount++;
            } 

            else if(bill == 10) {
                if(fiveCount > 0) {
                    fiveCount--;
                    tenCount++;
                } else {
                    return false;
                }
            }

            else {
                if(fiveCount > 0 && tenCount > 0) {
                    fiveCount--;
                    tenCount--;
                } else if(fiveCount >= 3 && tenCount == 0){
                    fiveCount -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;

        
    }
};
