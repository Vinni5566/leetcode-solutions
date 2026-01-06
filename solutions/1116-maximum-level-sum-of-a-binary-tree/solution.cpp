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
    int maxLevelSum(TreeNode* root) {
        
        //stores the maximum sum seen so far and the level at which it occurs
        //first  -> maximum level sum
        //second -> level number of that sum
        pair<int, int> maxLevelSum = {INT_MIN, 0}; 

        int currLevel = 0; //keeps track of current level

        //queue for BFS
        queue<TreeNode*> q; 
        q.push(root);

        //continue traversal until all levels are processed
        while(!q.empty()) {

            int size = q.size(); //number of nodes present at current level
            currLevel += 1;  //move to next level
            int currSum = 0;   //sum of node values at current level

            //process all nodes at a current level
            for(int i = 1; i <= size; i++) {

                TreeNode* node = q.front();

                q.pop();

                currSum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            //update maximum sum and level if current level sum is greater
            if(currSum > maxLevelSum.first) {
                maxLevelSum = {currSum, currLevel};
            }
        }

        //level having maximum sum
        return maxLevelSum.second;


    }
};
