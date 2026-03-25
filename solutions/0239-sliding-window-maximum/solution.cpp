class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        if(n == 1) return {nums[0]};
        if(k == 1) return nums;

        vector<int> res;

        priority_queue<pair<int, int>> pq;

        int i = 0;
        int j = 0;

        while(j < n) {
            pq.push({nums[j], j});

            if(j-i+1 < k) {
                j++;
            } else {

                while(pq.top().second < i) {
                    pq.pop();
                }

                res.push_back(pq.top().first);

                i++;
                j++;
            }
        }

        return res;

    }
};
