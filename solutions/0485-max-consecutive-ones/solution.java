class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int maxStreak = 0;  // keeps track of maximum consecutive 1s found so far
        int currentStreak = 0;  // counts current consecutive 1s

        for(int num : nums) {
            if(num == 1) {
                currentStreak += 1; //extend current streak
            } else {
                    if(currentStreak > maxStreak) {
                        maxStreak = currentStreak;
                    }

                    currentStreak = 0; //reset current streak (num == 0)
            }
        }

        // final check in case array ends with 1s
        if(currentStreak > maxStreak) {
            maxStreak = currentStreak;
        }

        return maxStreak;
    }
}
