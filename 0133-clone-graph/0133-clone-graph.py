# TC- O(h)
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
        self.dict = {}

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None

        if node in self.dict:
            return self.dict[node]
        
        new_node = Node(val=node.val)
        self.dict[node] = new_node
        if len(node.neighbors)>0:
            new_node.neighbors = []
        for i in range(len(node.neighbors)):
            neighbor = node.neighbors[i]
            new_node.neighbors.append(self.cloneGraph(neighbor))

        return new_node
