class MinStack {
private:
    stack<int> st;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(min.empty()) {
            min.push(val);
        } else {
            if(val <= min.top()) {
                min.push(val);
            }
        }
    }
    
    void pop() {

        if(!min.empty() && min.top() == st.top()) {
            min.pop();
        }

        if(!st.empty()) st.pop();
    }
    
    int top() {
        if(!st.empty()) return st.top();
        return -1;
    }
    
    int getMin() {
        if(!min.empty()) return min.top();
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
