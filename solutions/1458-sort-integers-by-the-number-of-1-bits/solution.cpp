class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        int n = arr.size();

        //base case
        if(n == 1) return arr;

        vector<int> numOf1(n);

        //calculate num of 1 bits in each integer
        for(int i = 0; i < n; i++) {
            numOf1[i] = calculateNumOf1(arr[i]);
        }

        //stores integers with same num of 1 bits together
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[numOf1[i]].push_back(arr[i]);
        }

        vector<int> res(n);

        int idx = 0;

        for(auto& pair : mp) {
            sort(pair.second.begin(), pair.second.end());
            for(int num : pair.second) {
                res[idx] = num;
                idx++;
            }

        }

        return res;
   
    }

    int calculateNumOf1(int n) {

        int count1 = 0;

        while(n > 0) {
            int r = n % 2;
            if(r == 1) count1++;
            n /= 2;
        }

        return count1;
    }


};
