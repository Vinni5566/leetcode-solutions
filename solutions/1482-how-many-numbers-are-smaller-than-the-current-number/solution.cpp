class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        int n = nums.size();
       
        int maximum = *max_element(nums.begin(), nums.end());  //max element
        int minimum = *min_element(nums.begin(), nums.end());  //min element

        //frequency vector
        vector<int> freq(maximum+1, 0);

        for(int num : nums) {
            freq[num]++;
        }

        //stores count of number of smaller elements for each element
        vector<int> minCount(maximum+1, 0);
        minCount[minimum] = 0;

        //converting frequencies to cumulative counts
        for(int i = minimum+1; i < maximum+1; i++) {
            minCount[i] = minCount[i-1] + freq[i-1]; //count of elements smaller than i
        }

        //stores countof smaller elements for elements in nums
        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            result[i] = minCount[nums[i]];
        }

        return result;  
        
    }
};
