class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {

        int n = words.size();

        unordered_map<string, int> mp;

        for(string word : words) {
            if(word.length() < k) continue;

            string subStr = word.substr(0, k);

            mp[subStr]++;
        }

        int countConnectedGroups = 0;

        for(auto& key : mp) {
            if(key.second >= 2) {
                countConnectedGroups++;
            }
        }

        return countConnectedGroups;
        
    }
};
