# Definition for a binary tree node.
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        node_queue = collections.deque([root])
        val_queue = collections.deque([root.val])
        while node_queue:
            node = node_queue.popleft()
            val = val_queue.popleft()
            if not node.left and not node.right: # 叶子
                if targetSum==val:
                    return True
            if node.left:
                node_queue.append(node.left)
                val_queue.append(node.left.val+val)
            if node.right:
                node_queue.append(node.right)
                val_queue.append(node.right.val+val)
        return False
