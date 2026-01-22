class Solution {
public:
    int numDecodings(string s) {

        int n = s.length();

        //dp[i] - no. of ways to decode substring starting at i
        vector<int> dp(n+1);

        //base case : at n
        dp[n] = 1;

        for(int i = n-1; i >= 0; i--) {

            //any decodings cannot start with 0
            if(s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            int num = stoi(s.substr(i, 2));

            dp[i] = dp[i+1];

            if(i+2 < n+1 && num >= 10 && num <= 26) {
                dp[i] += dp[i+2];
            }   

        }

        return dp[0];
     
    }
};
