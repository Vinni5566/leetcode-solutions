class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        long long MOD = 1e9 + 7;
       
        hFences.push_back(1);
        vFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        //stores possible distances between pair of fences
        unordered_set<int> hSet;
        unordered_set<int> vSet;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = 0; j < i; j++) {
                hSet.insert(hFences[i] - hFences[j]);
            }
        }

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = 0; j < i; j++) {
                vSet.insert(vFences[i] - vFences[j]);
            }
        }

        int maxLen = -1;

        //compute maximum side length of square
        for (int len : hSet) {
            if (vSet.count(len)) {
                maxLen = max(maxLen, len);
            }
        }

        if (maxLen == -1) return -1;  //impossible to make a square
        return (maxLen * 1LL * maxLen) % MOD;  //max area of square
    }
};

