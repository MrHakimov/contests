# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    answer = 0
    def dfs(self, root):
        
        if root == None:
            return -1

        left = self.dfs(root.left)
        right = self.dfs(root.right)
    
        current = max(left, right) + 1
        currentMax = left + 1 + right + 1
        self.answer = max(self.answer, currentMax)
        
        return current


    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.answer = 0
        self.dfs(root)
        return self.answer

