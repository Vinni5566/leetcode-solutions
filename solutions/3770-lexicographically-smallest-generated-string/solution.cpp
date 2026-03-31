class Solution {
public:
    string generateString(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        int len = n+m-1;
        string word(len, '?');
        vector<bool> locked(n+m-1, false);

        //handle T
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(word[i+j] == '?' || word[i+j] == str2[j]) {
                        word[i+j] = str2[j];
                        locked[i+j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        //fill remaining positions
        for(int i = 0; i < n+m-1; i++) {
            if(word[i] == '?') {
                word[i] = 'a';
            }
        }

        //handle F
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {

                string subStr = word.substr(i, m);

                if(subStr == str2) {

                    bool changed = false;

                    for(int j = m-1; j >= 0; j--) {

                        if(!locked[i+j]) {
                            if(str2[j] == 'a') {
                                word[i+j] = 'b';
                            } else if(str2[j] == 'b') {
                                word[i+j] = 'a';
                            } else {
                                word[i+j] = 'a';
                            }

                            if(checkT(str1, str2, word)) {
                                changed = true;
                                break;
                            }
                        }
                    }

                    if(!changed) return "";
                }
            }
        }

        return word;
        
    }

    bool checkT(string str1, string str2, string word) {

        int n = str1.length();
        int m = str2.length();

        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(word[i+j] != str2[j]) return false;
                }
            }
        }

        return true;
    }
};
