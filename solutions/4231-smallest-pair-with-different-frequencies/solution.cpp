class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return {-1, -1};

        unordered_map<int, int> mp;

        for(int num : nums) mp[num]++;

        int x = *min_element(nums.begin(), nums.end());
        int y = -1;

        for(auto& key : mp) {
            if(x < key.first && mp[x] != key.second) {
                if(y != -1) {
                    y = min(y, key.first);
                } else {
                    y = key.first;
                }
            }
        }

        if(y == -1) return {-1, -1};

        return {x, y};
        
    }
};
