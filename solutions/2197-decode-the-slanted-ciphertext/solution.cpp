class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        if(rows == 1) return encodedText;

        int l = encodedText.length();

        int cols = l/rows;

        vector<vector<char>> mat(rows, vector<char>(cols));

        int idx = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx];
                idx++;
            }
        }

        string res = "";

        
        for(int i = 0; i < cols; i++) {
            
            int j = 0;
            int k = i;

            while(j < rows && k < cols) {
                
                res.push_back(mat[j][k]);
                j++;
                k++;

                if(res.length() == l) break;
            }

        }

        trimTrailing(res);

        return res;  
        
    }

    void trimTrailing(string &s) {
        size_t last = s.find_last_not_of(' ');
        if (last != string::npos) {
            s.erase(last + 1);
        } else {
            s.clear(); // String was all spaces
        }
    }
};
