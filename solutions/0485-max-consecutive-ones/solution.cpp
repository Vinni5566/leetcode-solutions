class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxOnes = 0;
        int currOnes = 0;

        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] == 0) {
                maxOnes = max(maxOnes, currOnes);
                currOnes = 0;
                continue;
            }

            currOnes++;
        }

        maxOnes = max(maxOnes, currOnes);

        return maxOnes;
    }
};
