class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        int n = nums.size();

        if(n < 3) return -1;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;
        
        for(auto& p : mp) {
            if(p.second.size() >= 3) {
                vector<int> arr = p.second;
                sort(arr.begin(), arr.end());

                int i = 0;
                int j = 2;


                while(j < arr.size()) {
                    minDist = min(minDist, 2*(arr[j]-arr[i]));
                    i++;
                    j++;
                }
            }
        }

        if(minDist == INT_MAX) return -1;

        return minDist;
    }
};
