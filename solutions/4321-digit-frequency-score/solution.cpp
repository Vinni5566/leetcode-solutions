class Solution {
public:
    int digitFrequencyScore(int n) {
        
        unordered_map<int, int> freq;

        while(n > 0) {
            int d = n%10;
            freq[d]++;
            n/=10;
        }

        int score = 0;

        for(auto& p : freq) {
            score += (p.first*p.second);
        }

        return score;
    }
};
