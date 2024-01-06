# Definition for a binary tree node.
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root is None:
            return []
        res = []
        self.dfs(root, [], res)
        return res

    def dfs(self, cur: TreeNode, path: List[int], result: List[str]):
        if cur is None:
            return
        path.append(cur.val)
        if not cur.left and not cur.right:
            result.append('->'.join(map(str, path)))
        if cur.left:
            self.dfs(cur.left, path[:], result)
        if cur.right:
            self.dfs(cur.right, path[:], result)




