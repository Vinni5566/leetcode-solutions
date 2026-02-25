class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        unordered_map<int, vector<int>> mp;


        for(auto& key : freq) {
            mp[key.second].push_back(key.first);
        }

        for(int i = 0; i < n; i++) {
            if(mp[freq[nums[i]]].size() == 1) {
                return nums[i];
            }
        }

        return -1;
        
    }
};
