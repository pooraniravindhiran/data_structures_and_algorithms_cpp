# TC- O(n)
# SC- O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head is None or head.next is None or left==right:
            return head

        dummy = ListNode()
        dummy.next = head
        prev = dummy
        for _ in range(left-1):
            prev = prev.next
        
        curr = prev.next
        tail = curr
        for _ in range(right-left+1):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        tail.next = curr
        before = dummy
        for _ in range(left - 1):
            before = before.next
        before.next = prev

        return dummy.next