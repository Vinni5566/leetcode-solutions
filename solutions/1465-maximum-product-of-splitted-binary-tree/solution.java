/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    long maxProd = 0;
    long MOD = 1000000007L;

    public int maxProduct(TreeNode root) {
        long totalSum = sum(root);
        dfs(root, totalSum);

        return (int)(maxProd % MOD);
    }

    public long sum(TreeNode root) {
        if(root == null) return 0;
        return root.val + sum(root.left) + sum(root.right);
    }

    public long dfs(TreeNode root, long totalSum) {
        if(root == null) return 0;

        long left = dfs(root.left, totalSum);
        long right = dfs(root.right, totalSum);

        long currSum = root.val + left + right;
        maxProd = Math.max(maxProd, (totalSum - currSum)*currSum);

        return currSum;
    }
}
