class Solution {
public:
    int minDistance(string word1, string word2) {

        int l1 = word1.length();
        int l2 = word2.length();

        vector<vector<int>> dp(l1+1, vector<int>(l2+1));

        for(int i = 0; i <= l1; i++) {
            for(int j = 0; j <= l2; j++) {

                if(i == 0) {
                    dp[i][j] = j;   //insert j chars
                    continue;
                }

                if(j == 0) {
                    dp[i][j] = i;   //delete i chars
                    continue;
                }

                //if equal
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }

                dp[i][j] = min(
                    dp[i-1][j] + 1,  //delete from word1
                    min(
                        dp[i][j-1]+1,  //insert into word1
                        dp[i-1][j-1]+1  //replace from word1
                        ));
            }
        }
        
        return dp[l1][l2];  //min ops to convert word1 into word2
    }
};
