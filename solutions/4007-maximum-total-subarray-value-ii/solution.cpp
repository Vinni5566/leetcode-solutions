class Solution {
public:
    long long maxTotalValue(vector<int>& arr, int k) {
        int n = arr.size();
        int LOG = 32 - __builtin_clz(n);

        vector<vector<int>> maxST(n, vector<int>(LOG));
        vector<vector<int>> minST(n, vector<int>(LOG));

        for (int i = 0; i < n; i++) {
            maxST[i][0] = minST[i][0] = arr[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                maxST[i][j] = max(maxST[i][j - 1],
                                   maxST[i + (1 << (j - 1))][j - 1]);

                minST[i][j] = min(minST[i][j - 1],
                                   minST[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto getMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(maxST[l][j], maxST[r - (1 << j) + 1][j]);
        };

        auto getMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(minST[l][j], minST[r - (1 << j) + 1][j]);
        };

        priority_queue<tuple<int, int, int>> pq;

        for (int left = 0; left < n; left++) {
            int right = n - 1;
            int score = getMax(left, right) - getMin(left, right);
            pq.emplace(score, left, right);
        }

        long long result = 0;

        while (k--) {
            auto [score, l, r] = pq.top();
            pq.pop();

            result += score;

            if (r > l) {
                int newScore = getMax(l, r - 1) - getMin(l, r - 1);
                pq.emplace(newScore, l, r - 1);
            }
        }

        return result;
    }
};
