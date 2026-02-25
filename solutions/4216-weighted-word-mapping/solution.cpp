class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string res = "";

        for(string word : words) {
            int totalWeight = 0;

            for(char c : word) {
                totalWeight += weights[c-'a'];
            }

            int idx = 25 - (totalWeight%26);

            res += 'a'+idx;

        }

        return res;
        
    }
};
