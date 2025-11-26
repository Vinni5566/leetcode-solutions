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
    bool isBalanced(TreeNode* root) {
        int ans = checkHeightDifference(root);
        if(ans == -1) return false;
        return true;

    }

    int checkHeightDifference(TreeNode* root) {
        if (root == NULL) return 0;

        int lHeight = checkHeightDifference(root->left);
        if (lHeight == -1) return -1;

        int rHeight = checkHeightDifference(root->right);
        if (rHeight == -1) return -1;

        if (abs(lHeight - rHeight) > 1) return -1;

        return max(lHeight, rHeight) + 1;
    }
};
