class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length() != goal.length()) return false;
        if(s == goal) return true;
        return (s + s).find(goal) != string::npos;
    }
};
