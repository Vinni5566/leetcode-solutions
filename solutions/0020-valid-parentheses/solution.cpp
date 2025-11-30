class Solution {
public:
    bool isValid(string s) {

        if(s[0] == '}' || s[0] == ')' || s[0] == ']') return false;
        if(s.length() % 2 != 0) return false;
        
        
        stack<int> st;

        for(char c : s) {

            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if(!st.empty()) {
                    char curr = st.top();
                    if((curr == '{' && c == '}') || (curr == '(' && c == ')') || (curr == '[' && c == ']')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        if(!st.empty()) return false;

        return true;
    }
};
