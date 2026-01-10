class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        int l1 = s1.length();
        int l2 = s2.length();

        if(s1 == s2) return 0;

        //sum of ascii value of all character in both the strings
        int totalASCII = 0;

        for(char ch : s1) totalASCII += ch;
        for(char ch : s2) totalASCII += ch;

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

        for(int i = 1; i <= l1; i++) {
            for(int j =  1; j <= l2; j++) {

                //if both are equal
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] += dp[i-1][j-1] + s1[i-1];
                } 
                
                //skip i or skip j
                else {
                    dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        //min ascii sum deleted to make strings equal;
        return totalASCII - 2*dp[l1][l2]; 
    }

};
