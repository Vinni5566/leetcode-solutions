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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> par;

        for (auto &v : d) {
            if (!mp.count(v[0])) mp[v[0]] = new TreeNode(v[0]);
            if (!mp.count(v[1])) mp[v[1]] = new TreeNode(v[1]);
        }

        for (auto &v : d) {
            par[v[1]] = v[0];

            if (v[2]) {
                mp[v[0]]->left = mp[v[1]];
            } else {
                mp[v[0]]->right = mp[v[1]];
            }
        }

        for (auto &[x, node] : mp) {
            if (!par.count(x)) {
                return node;
            }
        }

        return nullptr;
    }
};
