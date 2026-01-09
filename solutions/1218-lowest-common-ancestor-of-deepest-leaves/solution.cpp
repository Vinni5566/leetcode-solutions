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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        return maxd(root).first;  
        
    }

    pair<TreeNode*, int> maxd(TreeNode* root) {

        if(root == NULL) return {NULL,0};

        auto l = maxd(root->left);
        auto r = maxd(root->right);

        if(l.second > r.second) {
            return {l.first, l.second+1};
        }

        if(l.second < r.second) {
            return {r.first, r.second+1};
        }

        return {root, l.second+1};

    }
};
