class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();

       vector<int> visited(n+1, 0);

       int missing = 0;
       int duplicate = 0;

        for(int num : nums) {

            if(visited[num] == 1) duplicate = num;
            visited[num] = 1;

        }

        for(int i = 1; i < n+1; i++) {
            if(visited[i] == 0) missing = i;
        }

        
        return {duplicate, missing};
    }
};
