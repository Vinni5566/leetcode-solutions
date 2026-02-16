class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store: {value : index}
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement already exists in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, store current number and its index
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};
