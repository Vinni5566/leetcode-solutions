class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> l(26);
        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            l[s[i] - 'a'] = i;
        }

        int st = 0;
        int en = 0;

        for (int i = 0; i < s.size(); i++) {
            en = max(en, l[s[i] - 'a']);
            if (i == en) {
                ans.push_back(en - st + 1);
                st = i + 1;
            }
        }
        return ans;
    }
};
