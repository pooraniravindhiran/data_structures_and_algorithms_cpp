# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# # TC- O(n)
# # SC- O(n)

# class Solution:
#     def inorderTraversal(self, node:Optional[TreeNode], nodes)->None:
#         if node is None:
#             return
#         self.inorderTraversal(node.left, nodes)
#         nodes.append(node.val)
#         self.inorderTraversal(node.right, nodes)

#     def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
#         nodes = []
#         self.inorderTraversal(root, nodes)
#         return nodes[k-1]

# TC- O(k)
# SC- O(h) - logn if balanced, n if skewed tree

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.count = 0
        self.ans = None

        def inorderTraversal(node):
            if node is None:
                return
            inorderTraversal(node.left)
            self.count += 1
            if self.count==k:
                self.ans= node.val
                return
            inorderTraversal(node.right)

        inorderTraversal(root)
        return self.ans
        
        