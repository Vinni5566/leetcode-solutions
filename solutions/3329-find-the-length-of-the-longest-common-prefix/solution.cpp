class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> prefix;

        for(int x : arr1) {

            while(x > 0) {
                prefix.insert(x);
                x /= 10;
            }
        }

        int mx = 0;

        for(int x : arr2) {

            int num = x;

            int curr = 0;

            while(num > 0) {
                if(prefix.contains(num)) curr++;
                num /= 10;
            }

            mx = max(mx, curr);
        }

        return mx;

    }
};
