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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL) return new TreeNode(val);
        
        TreeNode* temp = root;
        TreeNode* parent = NULL;
        TreeNode* node = new TreeNode(val);

        while(temp != NULL) {
            parent = temp;

            if(temp->val < val) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        if(parent->val < val) {
            parent->right = node;
        } else {
            parent->left = node;
        }

        return root;
    }
};
