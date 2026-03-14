class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> freq;

        for(int num : nums1) {
            freq[num]++;
        }

        for(int num : nums2) {
            freq[num]++;
        }

        for(auto& p : freq) {
            if(p.second % 2 != 0) {
                return -1;
            }
        }

        int minCost = 0;

        unordered_map<int, int> f1;
        unordered_map<int, int> f2;

        for(int num : nums1) {
            f1[num]++;
        }

        for(int num : nums2) {
            f2[num]++;
        }

        for(auto& p : f1) {
            if(p.second > freq[p.first]/2) {
                minCost += (p.second - freq[p.first]/2);
            }
        }
        
        return minCost;
        
    }
};
