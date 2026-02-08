class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int n = nums.size();
        deque<int> maxdq, mindq;

        long long count = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {

            while (!maxdq.empty() && nums[maxdq.back()] <= nums[r]) {
                maxdq.pop_back();
            }
            maxdq.push_back(r);

            while (!mindq.empty() && nums[mindq.back()] >= nums[r]) {
                mindq.pop_back();
            }
            mindq.push_back(r);

            while (!maxdq.empty() && !mindq.empty()) {
                long long maxi = nums[maxdq.front()];
                long long mini = nums[mindq.front()];
                long long len = r - l + 1;
                long long cost = (maxi - mini) * len;

                if (cost <= k) break;

                if (maxdq.front() == l) maxdq.pop_front();
                if (mindq.front() == l) mindq.pop_front();
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }
};
