class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        int n = nums.size();

        int player1Score = 0;
        int player2Score = 0;

        bool player1Active = true;

        for(int i = 0; i < n; i++) {

            if(nums[i] % 2 != 0) {
                player1Active = !player1Active;
            }

            if((i+1) % 6 == 0) {
                player1Active = !player1Active;
            }

            if(player1Active) {
                player1Score += nums[i];
            } else {
                player2Score += nums[i];
            }
        }

        return player1Score - player2Score;
        
    }
};
