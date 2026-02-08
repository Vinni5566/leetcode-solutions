class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        stack<long long> st;
        
        for (int x : nums) {
            
            if (!st.empty() && st.top() == x) {
                long long top = st.top();
                st.pop();
                top *= 2;
                
                while(!st.empty() && top == st.top()) {
                    st.pop();
                    top *= 2;
                }

                st.push(top);

            } else {
                st.push(x);
            }
        }
        
        vector<long long> res(st.size());
        
        for (int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
        
    }
};
