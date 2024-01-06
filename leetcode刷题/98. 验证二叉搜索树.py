# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, lower=float('-inf'), upper=float('inf')):
            if not root:
                return True
            val = root.val
            if val <= lower or val >= upper:
                return False
            if not dfs(root.left, lower, val):
                return False
            if not dfs(root.right, val, upper):
                return False
            return True
        return dfs(root)
