class CustomStack {
private:
    vector<int> st;
    int top = -1;

public:
    CustomStack(int maxSize) {
        st.resize(maxSize);
    }
    
    void push(int x) {

        if(top == st.size()-1) return;

        top += 1;
        st[top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;

        int popedEle = st[top];

        top -= 1;

        return popedEle;
    }
    
    void increment(int k, int val) {
        
        for(int i = 0; i < min(k, top+1); i++) {
                st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
