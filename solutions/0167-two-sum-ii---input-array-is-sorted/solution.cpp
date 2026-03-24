class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        vector<int> res(2);

        int l = 0;
        int h = n-1;

        while(l < h) {
            if(numbers[l] + numbers[h] == target) {
                res[0] = l+1;
                res[1] = h+1;
                break;
            } else if(numbers[l] + numbers[h] > target) {
                h--;
            } else {
                l++;
            }
        }

        return res;
    }
};
