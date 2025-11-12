class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int l = heights.size();

        if(l == 1) return heights[0];
        if(l == 2) {
            if(heights[0] == heights[1]) {
                return heights[0]*2;
            } else {
                int a1 = max(heights[0], heights[1]);
                int a2 = min(heights[0], heights[1])*2;
                
                return max(a1, a2);
            }
            
        }

        
        stack<int> st;
        int maxarea = 0;
        int i = 0;

        while(i <= l) {
            int currHeight = (i == l ? 0 : heights[i]);
            if(st.empty() || heights[st.top()] < currHeight) {
                st.push(i);
                i++;
            } else {
                int topEle = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = heights[topEle] * width;
                maxarea = max(area, maxarea);
            }
        }

        return maxarea;   

    }
};
