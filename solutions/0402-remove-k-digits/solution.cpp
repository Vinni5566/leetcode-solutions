class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string s;
        stack<char> st;

        for(int i = 0; i < num.length(); i++) {

            char curr = num[i];
            
            while(!st.empty() && st.top() > curr && k > 0) {
                st.pop();
                k--;
            }

            st.push(curr);
        }

        //handling when k is > 0
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        //pushing rest of digits from in s
        while(!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }

        //removing leading zeros
        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] == '0') s.pop_back();
            else break;
        }

        //reversing s
        reverse(s.begin(), s.end());

        if(s == "") return "0";

        return s;

        
    }
};
