# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# TC- O(n)
# SC- O(h)

class Solution:
    def isInInterval(self, node, mini, maxi) -> bool:
        if node is None:
            return True
        elif not (mini<node.val<maxi):
            return False
        return self.isInInterval(node.left, mini, node.val) and self.isInInterval(node.right, node.val, maxi)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.isInInterval(root, float('-inf'), float('inf'))