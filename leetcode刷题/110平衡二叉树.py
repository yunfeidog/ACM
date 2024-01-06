# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root) >= 0

    def dfs(self, root: TreeNode) -> int:
        if root is None:
            return 0
        leftHeight = self.dfs(root.left)
        rightHeight = self.dfs(root.right)
        if leftHeight == -1 or rightHeight == -1 or abs(leftHeight - rightHeight) > 1:
            return -1
        else:
            return max(leftHeight, rightHeight) + 1
