class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> freq(26, 0);

        for(char c : s) {
            freq[c-'a']++;
        }

        vector<bool> visited(26, false);

        stack<char> st;

        for(char c : s) {

            int idx = c-'a';
            freq[idx]--;

            if(visited[idx]) continue;

            while(!st.empty() && st.top() > c && freq[st.top()-'a'] > 0) {
                visited[st.top()-'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[idx] = true;
        }

        string res;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
