class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(int curr : asteroids) {
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && curr < 0) {
                if(abs(st.top()) < abs(curr)) {
                    st.pop();  // top explodes
                } else if(abs(st.top()) == abs(curr)) {
                    st.pop();  // both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // current explodes
                    break;
                }
            }

            if(!destroyed) {
                st.push(curr);
            }
        }

        vector<int> res(st.size());
        for(int i = res.size()-1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
        
    }
};
