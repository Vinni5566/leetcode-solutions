class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int totalSum = 0; 

        for(int num : nums) {
            totalSum += getdivisor(num);
        }

        //result
        return totalSum;
        
    }

    int getdivisor(int n) {

        //base case
        if(n < 6) return 0;

        int divisorCount = 0;
        int divisorSum = 0;

        //iterate to sqrt(n) to find divisors pair
        for(int i = 1; i*i<= n; i++) {

            if(n%i == 0) {

                //perfect square: contributes only one divisor
                if(i*i == n) {
                    divisorCount++;
                    divisorSum += i;
                    continue;
                }

                // count both i and n/i
                divisorCount += 2;

                if(divisorCount > 4) return 0;  //early exit if more than 4 divisors found

                divisorSum += i;
                divisorSum += n/i;
            }
        }

        // valid only if the number has exactly 4 divisors
        if(divisorCount == 4) return divisorSum;

        return 0;
    }
};
