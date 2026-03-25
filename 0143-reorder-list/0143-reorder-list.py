# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# TC- O(n)
# SC- O(1)

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # find middle
        slowptr = head
        fastptr = head
        while(fastptr and fastptr.next):
            slowptr = slowptr.next
            fastptr = fastptr.next.next
        
        # reverse second half
        prev = None
        curr = slowptr.next
        slowptr.next = None
        while(curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        # merge
        slowptr = head
        fastptr = prev
        while(fastptr):
            temp1 = slowptr.next
            temp2 = fastptr.next

            slowptr.next = fastptr
            fastptr.next = temp1

            slowptr = temp1
            fastptr = temp2


        
        