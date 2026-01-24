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
    void flatten(TreeNode* root) {

        if(root == NULL) return;
        
        vector<int> preorder;

        preorderTraversal(root, preorder);

        root->left = NULL;
        root->right = NULL;

        TreeNode* temp = root;

        for(int i = 1; i < preorder.size(); i++) {

            TreeNode* t = new TreeNode(preorder[i]);

            temp->right = t;
            temp = temp->right;

        }

    }

    void preorderTraversal(TreeNode* root, vector<int>& preorder) {

        if(root == NULL) return;

        preorder.push_back(root->val);

        preorderTraversal(root->left, preorder);
        preorderTraversal(root->right, preorder);

    }
};
