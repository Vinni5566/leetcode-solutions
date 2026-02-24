class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> nge(n2);
        vector<int> res(n1);

        stack<int> st;

        for(int i = n2-1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int i = 0; i < n1; i++) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            int idx = it - nums2.begin();

            res[i] = nge[idx];
        }

        return res;
  
    }
};
