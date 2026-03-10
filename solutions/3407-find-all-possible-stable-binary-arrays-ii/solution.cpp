class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        int MOD = 1e9 + 7;

        //t[zero+1][one+1][2] 
        vector<vector<vector<int>>> t(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));

        for(int i = 0; i <= min(zero, limit); i++) {
            t[i][0][0] = 1;
        }
        
        for(int j = 0; j <= min(one, limit); j++) {
            t[0][j][1] = 1;
        }

        for(int i = 0; i <= zero; i++) { //i = # 0s
            for(int j = 0; j <= one; j++) { //j = # 1s

                if(i == 0 || j == 0) {
                    continue;
                }

                t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % MOD;
                
                if(j-1 >= limit) {
                    t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + MOD) % MOD;
                }

                t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % MOD;
                
                if(i-1 >= limit) {
                    t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + MOD) % MOD;
                }
            }
        }

        return (t[zero][one][0] + t[zero][one][1]) % MOD;
        
    }
};
