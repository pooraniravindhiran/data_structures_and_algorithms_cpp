# TC- O(n+e)
# SC- O(n)

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def __init__(self):
        self.clone_dict = {}

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        if node in self.clone_dict:
            return self.clone_dict[node]
        
        self.clone_dict[node] = Node(node.val)
        for neigh in node.neighbors:
            self.clone_dict[node].neighbors.append(self.cloneGraph(neigh))
        return self.clone_dict[node]
         
      
