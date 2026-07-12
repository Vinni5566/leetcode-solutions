class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        if(arr.empty()) return {};
        if(arr.size() == 1) return {1};
        
        vector<int> sorted = arr;
        sort(sorted.begin(),sorted.end());
        vector<int> rank(sorted.size());
        

        rank[0] = 1;

        for(int i = 1; i < sorted.size(); i++) {
            if(sorted[i] != sorted[i-1]) {
                rank[i] = rank[i-1]+1;
            } else {
                rank[i] = rank[i-1];
            }
        }

        unordered_map<int, int> mp;

        for(int i = 0; i < sorted.size(); i++) {
            mp[sorted[i]] = rank[i];
        }

        vector<int> res(sorted.size());

        for(int i = 0; i < sorted.size(); i++) {
            res[i] = mp[arr[i]];
        }
        
        return res;
    }
};
