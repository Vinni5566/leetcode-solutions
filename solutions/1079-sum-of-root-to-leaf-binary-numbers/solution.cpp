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
    int sumRootToLeaf(TreeNode* root) {

        int res = 0;
        int curr = 0;

        dfs(root, res, curr);

        return res;
        
    }

    void dfs(TreeNode* root, int& res, int curr) {

        if (!root) return;   

        // update current binary value
        curr = curr * 2 + root->val;

        // if leaf, add to result
        if (!root->left && !root->right) {
            res += curr;
            return;
        }

        dfs(root->left, res, curr);
        dfs(root->right, res, curr);

    }


};
