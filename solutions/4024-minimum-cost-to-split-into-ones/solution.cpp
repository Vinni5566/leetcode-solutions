class Solution {
public:
    int minCost(int n) {

        if(n == 1) return 0;
        if(n == 2) return 1;

        vector<int> dp(n);

        dp[0] = 0; //cost of splitting 1 into ones
        dp[1] = 1; //cost of splitting 2 into ones

        for(int i = 3; i <= n; i++) {

            //cost of splitting i into ones
            dp[i-1] = i-1+dp[i-2];
        }

        return dp[n-1];
        
    }
};
