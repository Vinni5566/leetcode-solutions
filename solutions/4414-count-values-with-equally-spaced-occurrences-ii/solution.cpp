class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n = nums.size();
        
        unordered_map<int, pair<int, vector<int>>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].first += 1;
            mp[nums[i]].second.push_back(i);
        }

        int res = 0;

        for(auto& p : mp) {
            if(p.second.first >= 3) {
                vector<int> freq = p.second.second;

                int diff = freq[1] - freq[0];
                bool isEquallySpaced = false;

                for(int i = 2; i < freq.size(); i++) {
                    if(freq[i] - freq[i-1] != diff) {
                        isEquallySpaced = true;
                        break;
                    }
                }

                if(!isEquallySpaced) res++;
            }
        }

        return res;
    }
};
