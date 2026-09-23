class Solution {
public:
    bool isHappy(int n) {
        
        if(n <= 9) {
            if(n == 1 || n == 7) return true;
            else return false;
        }

        int sum = 0;

        while(sum == 0 || sum > 9) {

            sum = 0;

            while(n > 0) {
                int r = n%10;
                sum += (r * r);
                n /= 10;
            }

            n = sum;
        }

        if(sum == 1 || sum == 7) return true;
        
        return false;


    }
};
