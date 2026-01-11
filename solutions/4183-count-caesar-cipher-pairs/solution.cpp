class Solution {
public:
    long long countPairs(vector<string>& words) {

        int n = words.size();
        int m = words[0].size();

        unordered_map<string, long long> mp;
        
        long long count = 0;

        for(auto& w : words) {
            string s;
            for(int i = 0; i < m; i++) {
                int currD = (w[i] - w[0] + 26) % 26;
                s.push_back('a' + currD);
            }

            count += mp[s];

            mp[s]++;
        }

        return count;
    }
};
