class Solution {
public:
    bool checkValidString(string s) {

        stack<int> openBrackets;
        stack<int> starPositions;

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];

            if(ch == '(') {
                openBrackets.push(i);
            }

            if(ch == '*') {
                starPositions.push(i);
            }

            if(ch == ')') {
                if(!openBrackets.empty()) openBrackets.pop();
                else if(!starPositions.empty()) starPositions.pop();
                else return false;
            }
        }

        while(!openBrackets.empty()) {
            if(starPositions.empty()) return false;
            if(openBrackets.top() > starPositions.top()) return false;
            
            starPositions.pop();
            openBrackets.pop();
        }

        return true;
        
    }
};
