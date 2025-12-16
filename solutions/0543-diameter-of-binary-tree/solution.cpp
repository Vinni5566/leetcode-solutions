/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
        int maxDiameter = 0;
        calculateDiameter(root, maxDiameter);
        return maxDiameter;
        
    }

    int calculateDiameter(TreeNode* root, int &maxDiameter) {
        if(root == NULL) return 0;
        
        int leftHeight = calculateDiameter(root->left, maxDiameter);
        int rightHeight = calculateDiameter(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, (leftHeight+rightHeight));

        return max(leftHeight, rightHeight)+1;
    }
};
    

