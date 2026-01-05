class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;  //stores operands

        for(string s : tokens) {

            //if operator is found pop 2 elements perform operation and push result in the stack
            if(s == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();

                st.push(top2 + top1);
            } else if(s == "*") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();

                st.push(top2 * top1);
            } else if(s == "-") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();

                st.push(top2 - top1);
            } else if (s == "/") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();

                //division by 0 avoided
                if(top1 == 0) {
                    st.push(0);
                    continue;
                }

                //division follows truncation towards zero
                st.push(top2 / top1);
            } else {

                //operand, push into stack
                st.push(stoi(s));
            }
        }

        return st.top(); //value of expression
        
    }
};
