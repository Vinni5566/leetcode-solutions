class Solution {
public:
    string reverseWords(string s) {

        //remove leading spaces
        while (!s.empty() && s[0] == ' ') {
            s.erase(0, 1);
        }

        //remove trailing spaces
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        //reverse whole string
        reverse(s.begin(), s.end());

        //remove extra spaces
        int j = 0;

        for(int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && j > 0 && s[j - 1] == ' ') continue;

            s[j++] = s[i];
        }

        s.resize(j);

        //reverse each word
        int start = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;

    }
};
