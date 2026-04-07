class Solution {
public:
    string removeDuplicates(string s) {
        
        int l = s.length();

        int i = 0;

        stack<char> st;

        for(int i = 0; i < l; i++) {

            if(st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                while(!st.empty() && st.top() == s[i]) {
                    st.pop();
                }
            }
            
        }

        string res = "";

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
