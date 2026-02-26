class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        if(str1 == str2) return str1;

        int l1 = str1.length();
        int l2 = str2.length();

        //build dp table to find length of lcs
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

        for(int i = 1; i < l1+1; i++) {
            for(int j = 1; j < l2+1; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        //build shortest supersequence by backtracking dp table
        string res = "";

        int i = l1;
        int j = l2;

        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) { //both are equal append only once, move both i and j
                res += str1[i-1];
                i--;
                j--;
            } else {
                if(dp[i][j-1] > dp[i-1][j]) { //go left, append char from str2 in res
                    res += str2[j-1];
                    j--;
                } else {   //go up, append char from str1 in res
                    res += str1[i-1];
                    i--;
                }
            }
        }

        //if one string exhaust early, append rest of chars from other string in res
        while(i > 0) {
            res += str1[i-1];
            i--;
        }

        while(j > 0) {
            res += str2[j-1];
            j--;
        }

        //reverse res 
        reverse(res.begin(), res.end());

        return res;

        
    }
};
