class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int n = g.size();
        int m = s.size();

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0; //cookie size
        int j = 0; //greed
        
        int numOfContentChildren = 0;

        while(i < m && j < n) {
            if(s[i] >= g[j]) {
                i++;
                j++;
                numOfContentChildren++;
            } else {
                i++;
            }
        }

        return numOfContentChildren;
    }
};
