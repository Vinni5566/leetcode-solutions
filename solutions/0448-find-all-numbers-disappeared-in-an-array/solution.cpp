class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();

        //vector to keep track of numbers appeared
        vector<int> visited(n+1, 0);  

        for(int num : nums) {
            visited[num] = 1;
        }

        vector<int> result;

        for(int i = 1; i < n+1; i++) {
            if(visited[i] == 0) result.push_back(i); //number do not appear
        }

        return result;
    }
};
