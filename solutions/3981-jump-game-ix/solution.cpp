class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>res(n);

        vector<int> maxi(n);
        maxi[0] = nums[0];

        vector<int> mini(n);
        mini[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {
            maxi[i] = max(nums[i], maxi[i-1]);
        }

        for(int i = n-2; i >= 0; i--) {
            mini[i] = min(nums[i], mini[i+1]);
        }

        int start = 0;
        int blockMax = nums[0];

        for (int i = 0; i < n; i++) {
            blockMax = max(blockMax, nums[i]);

            if (i == n - 1 || maxi[i] <= mini[i + 1]) {
                for (int j = start; j <= i; j++) {
                    res[j] = blockMax;
                }

                start = i + 1;
                if (start < n) {
                    blockMax = nums[start];
                }
            }
        }  

        return res;

    }
};
