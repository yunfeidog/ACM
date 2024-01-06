# Definition for a binary tree node.
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def dfs(l, r) -> TreeNode:
            if l > r:
                return None
            mx = nums[l]
            idx = l
            for i in range(l, r + 1):
                if nums[i] > mx:
                    mx = nums[i]
                    idx = i
            root = TreeNode(mx)
            root.left = dfs(l, idx - 1)
            root.right = dfs(idx + 1, r)
            return root

        return dfs(0, len(nums) - 1)
