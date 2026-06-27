class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int n= nums.size();

        sort(nums.begin(), nums.end());

        map<long long, int> mp;
        unordered_set<long long> set;
        for(int num : nums) {
            mp[num]++;
            set.insert(num);
        }

        int len = 1;

        if(mp[1]) {
            if (mp[1] % 2 == 0) len = max(len, mp[1] - 1);
            else len = max(len, mp[1]);
        }

        int i = 0;

        while(i < n) {

            if(mp[nums[i]] < 2 || nums[i] == 1) {
                i++;
                continue;
            }

            long long num = nums[i];
            int l = 1;

            while (mp[num] >= 2) {

                if (num > LLONG_MAX / num) break;

                long long square = num * num;
                if (!set.contains(square)) break;

                num = square;
                l += 2;
            }

            len = max(len, l);

            i++;
        }

        return len;

    }
};
