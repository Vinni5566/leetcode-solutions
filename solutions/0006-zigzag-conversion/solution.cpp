class Solution {
public:
    string convert(string s, int numRows) {

        int l = s.length();

        if(numRows == 1 || l == 1) return s;

        vector<vector<char>> str(numRows, vector<char>(1000, ' '));

        bool straight = true;

        int i = 0;
        int j = 0;

        for(int idx = 0; idx < l; idx++) {

            if(straight) {

                //if last row, set straight = false and go diagonal
                if(i == numRows-1) {
                    straight = false;
                    str[i][j] = s[idx];
                    i--;
                    j++;
                    continue;
                }

                //downward movement
                str[i][j] = s[idx];
                i++;

            } else {
                
                //if top row, set straight = truw and go down(straight)
                if(i == 0)  {
                    str[i][j] = s[idx];
                    i++;
                    straight = true;
                    continue;
                }
                
                //diagonal movement
                str[i][j] = s[idx];
                i--;
                j++;
            } 
        }

        string res;

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < 1000; j++) {
                if(s.length() == res.length()) break;
                if(str[i][j] != ' ') res.push_back(str[i][j]);
            }
        }

        return res;
   
    }
};
