class Solution {
public:
    bool backspaceCompare(string s, string t) {

        if(s == t) return true;
    
        stack<char> st1;
        stack<char> st2;

        for(char c : s) {
            if(c == '#') {
                if(!st1.empty()) st1.pop();
                else continue;
            } else {
                st1.push(c);
            }
        }

        for(char c : t) {
            if(c == '#') {
                if(!st2.empty()) st2.pop();
                else continue;
            } else {
                st2.push(c);
            }
        }

        if(st1.size() != st2.size()) return false;

        while(!st1.empty() && !st2.empty()) {
            if(st1.top() != st2.top()) {
                return false;
            } else {
                st1.pop();
                st2.pop();
            }
        }

        return st1.size() == st2.size();

    }
};
