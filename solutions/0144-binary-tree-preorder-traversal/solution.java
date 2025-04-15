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
    ArrayList<Integer> lst = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {

        if(root == null) return lst;

        TreeNode temp = root;
        
        lst.add(temp.val);
        preorderTraversal(temp.left);
        preorderTraversal(temp.right);

        return lst;
    }
}
