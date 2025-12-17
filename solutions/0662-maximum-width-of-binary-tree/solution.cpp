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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();
            long long base = q.front().second;
            long long left = 0, right = 0;

            for(int i = 0; i < size; i++) {
                auto front = q.front(); q.pop();
                TreeNode* node = front.first;
                long long idx = front.second - base;

                if(i == 0) left = idx;
                if(i == size - 1) right = idx;

                if(node->left)
                    q.push({node->left, 2 * idx});

                if(node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            maxWidth = max(maxWidth, right - left + 1);
        }

        return maxWidth;

    }
};
