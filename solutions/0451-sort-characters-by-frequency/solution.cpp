class Solution {
public:
    string frequencySort(string s) {
        
        string res;

        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }

        vector<pair<int, char>> freqs;
        for(auto& p : mp) {
            freqs.push_back({p.second, p.first});
        }

        sort(freqs.begin(), freqs.end(), [](pair<int,char> &a, pair<int,char> &b){
            return a.first > b.first;
        });


        for(auto& p : freqs) {
            for(int i = 0; i < p.first; i++) {
                res.push_back(p.second);
            }
        }

        return res;
    }
};
