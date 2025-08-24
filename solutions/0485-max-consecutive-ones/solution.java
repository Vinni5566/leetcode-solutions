class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int maxStreak = 0;  // keeps track of maximum consecutive 1s found so far
        int currentStreak = 0;  // counts current consecutive 1s

        for(int num : nums) {
            if(num == 0) {
                currentStreak = 0;
            } else {
                currentStreak += 1;
            }

            if(maxStreak < currentStreak) maxStreak = currentStreak;
        }

        return maxStreak;
    }
}
