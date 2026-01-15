class Solution {
public:
    string removeDuplicateLetters(string s) {

        int n = s.length();

        // stores frequency of remaining characters in the string
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;

        // tracks which characters are currently in the stack
        vector<bool> visited(26, false);

        // stack to build the result in lexicographically increasing order
        stack<char> st;

        for(char ch : s) {
            int idx = ch - 'a';

            // decrement remaining count of current character
            freq[idx]--;

            // skip if character is already in stack
            if(visited[idx]) continue;

            // remove characters from stack if:
            // they are greater than current character (to get smaller lex order)
            // they will appear later again (safe to remove)
            while(!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            // push current character into stack and mark it visited
            st.push(ch);
            visited[idx] = true;
        }

        // pop all characters from stack to form the result string
        string res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        // reverse because stack stores characters in reverse order
        reverse(res.begin(), res.end());

        return res;  // lexicographically smallest unique string
    }
};

