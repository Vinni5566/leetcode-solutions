class Solution {
public:
    int beautySum(string s) {
        
        int beautySum = 0;

        for(int i = 0; i < s.length(); i++) {

            unordered_map<char, int> freq;

            for(int j = i; j < s.length(); j++) {
                freq[s[j]]++;

                int max_freq = 0;
                int min_freq = INT_MAX;

                for(auto it : freq) {
                    max_freq = max(max_freq, it.second);
                    min_freq =  min(min_freq, it.second);
                }

                beautySum += max_freq - min_freq;
            }
        }

        return beautySum;
    }
};
