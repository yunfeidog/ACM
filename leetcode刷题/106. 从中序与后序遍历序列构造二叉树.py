# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def dfs(l, r) -> TreeNode:
            if l > r:
                return None
            val = postorder.pop()
            root = TreeNode(val)
            idx = mp[val]
            root.right = dfs(idx + 1, r)
            root.left = dfs(l, idx - 1)
            return root

        mp = {}
        for i in range(len(inorder)):
            mp[inorder[i]] = i
        return dfs(0, len(inorder) - 1)
