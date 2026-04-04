# TC- O(n)
# SC- O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        slowptr = dummy
        fastptr = dummy

        while n>=0:
            fastptr = fastptr.next
            n -= 1
        
        while fastptr:
            slowptr = slowptr.next
            fastptr = fastptr.next

        slowptr.next = slowptr.next.next

        return dummy.next