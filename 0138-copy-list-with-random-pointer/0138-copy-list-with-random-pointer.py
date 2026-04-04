"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
# TC- O(n)
# SC- O(n)
class Solution:
    def __init__(self):
        self.mapping = {}

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None

        if head in self.mapping:
            return self.mapping[head]

        curr = ListNode(head.val)
        self.mapping[head] = curr
        curr.next = self.copyRandomList(head.next)
        curr.random = self.copyRandomList(head.random)
        
        return curr