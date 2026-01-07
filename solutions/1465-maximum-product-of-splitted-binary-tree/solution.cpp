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
    long long MOD = 1e9 + 7;
    long long maxProd = 0;

    int maxProduct(TreeNode* root) {

        long long totalSum = sum(root);
        dfs(root, totalSum);

        return maxProd % MOD; //max product of sum of subtrees


    }

    //calculates sum of values of all nodes in the tree
    long long sum(TreeNode* root) {
        if(!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    long long dfs(TreeNode* root, long long totalSum) {

        if(root == NULL) return 0;

        long long left = dfs(root->left, totalSum);
        long long right = dfs(root->right, totalSum);

        long long currSum = root->val + left + right;
        maxProd = max(maxProd, currSum * (totalSum - currSum));

        return currSum;
    }

};
