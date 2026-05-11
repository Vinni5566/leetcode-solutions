class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        if(n == 0) return {{""}};
        if(n == 1) return {{strs[0]}};

        unordered_map<string, vector<int>> mp;

        for(int i = 0; i < n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());

            mp[s].push_back(i);
        }

        vector<vector<string>> res;

        for(auto& p : mp) {

            vector<string> grp;

            for(int idx : p.second) {
                grp.push_back(strs[idx]);
            }

            res.push_back(grp);
        }

        return res;
        
    }
};
