class Solution {
public:
    int numberOfSpecialChars(string word) {

        int l = word.length();

        int count = 0;

        unordered_map<char, pair<int, int>> mp;

        for(int i = 0; i < l; i++) {

            char c = word[i];

            if(islower(c)) {
                if(mp.find(c) == mp.end()) mp[c] = {-1, l};
                mp[c].first = i;
            }

            if(isupper(c)) {
                char lower_c = tolower(c); 
                if(mp.find(lower_c) == mp.end()) mp[lower_c] = {-1, l};
                mp[lower_c].second = min(mp[lower_c].second, i);
            }
        }

        for(auto& p : mp) {

            if(p.second.first != -1 && p.second.second != l && p.second.first < p.second.second) {
                count++;
            }
        }

        return count;
        
    }
};
