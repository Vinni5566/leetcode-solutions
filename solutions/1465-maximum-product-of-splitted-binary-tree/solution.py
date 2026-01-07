# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:

        MOD = 10**9 + 7
        self.maxProd = 0

        def sum(node):
            if not node:
                return 0
            return node.val + sum(node.left) + sum(node.right)
        
        totalSum = sum(root)

        def dfs(node, totalSum):
            if not node:
                return 0
            
            left = dfs(node.left, totalSum)
            right = dfs(node.right, totalSum)

            currSum = node.val + left + right

            self.maxProd = max(self.maxProd, currSum * (totalSum - currSum))

            return currSum
        
        dfs(root, totalSum)
        return self.maxProd % MOD
