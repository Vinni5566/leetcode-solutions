class Solution {
public:
    int pivotInteger(int n) {

        if(n == 1) return 1;

        int totalSum = 0;

        for(int i = 1; i <= n; i++) {
            totalSum += i;
        }

        int leftSum = 1;
        int rightSum = totalSum;

        for(int i = 2; i < n; i++) {
            leftSum += i;
            rightSum = totalSum - leftSum + i;

            if(leftSum == rightSum) return i;
        }

        return -1;
        
    }
};
