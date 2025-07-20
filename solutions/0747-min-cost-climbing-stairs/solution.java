class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] memo = new int[n];
        Arrays.fill(memo, -1);

        int res = Math.min(helper(0, cost, memo), helper(1, cost, memo));

        return res;
    }

    public int helper(int i, int[]cost, int[] memo) {
            if(i >= cost.length) return 0;

            if(memo[i] != -1) return memo[i];

            int oneStep = helper(i+1, cost, memo);
            int twoStep = helper(i+2, cost, memo);

            memo[i] = cost[i] + Math.min(oneStep, twoStep);

            return memo[i];
        }

}
