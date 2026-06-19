class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();

        vector<int> res(n+1);
        res[0] = 0;

        for(int i = 1; i <= n; i++) {
            res[i] = res[i-1]+gain[i-1];
        }

        return *max_element(res.begin(), res.end());
    }
};
