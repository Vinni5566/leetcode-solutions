class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        
        unordered_map<int, int> freq;

        for(int bulb : bulbs) {
            freq[bulb]++;
        }

        vector<int> res;

        for(int i = 1; i <= 100; i++) {
            
            if(freq[i] % 2 == 1) {
                res.push_back(i);
            }
        }

        return res;
    }
};
