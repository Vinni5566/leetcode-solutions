class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();

        string res = "";

        for(int i = 0; i < n; i++) {
            //the resultant string shouldn;t match any string
            //so, whatever nums[i][i], we take opposite of it
            //this gurantees mistmatch for every string
            if(nums[i][i] == '1') res += '0';
            else res += '1';
        }

        return res;
        
    }
};
