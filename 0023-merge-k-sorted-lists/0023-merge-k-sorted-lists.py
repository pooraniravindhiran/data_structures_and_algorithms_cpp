# TC- O(nlogk)
# SC- O(k)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummy = ListNode()
        curr = dummy
        min_heap = []

        for idx, l in enumerate(lists):
            if l:
                # If values tie, i avoids comparing ListNode objects directly (which causes error in Python).
                heapq.heappush(min_heap, (l.val, idx, l))
        
        while min_heap:
            min_elem, idx, l = heapq.heappop(min_heap)
            curr.next = l
            curr = curr.next
            l = l.next
            if l:
                heapq.heappush(min_heap, (l.val, idx, l))
        
        return dummy.next