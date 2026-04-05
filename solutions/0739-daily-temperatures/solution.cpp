class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> res(n);
        
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }

        res[n-1] = 0;

        return res;
        
    }
};
