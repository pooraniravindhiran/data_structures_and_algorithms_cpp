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
                heapq.heappush(min_heap, (l.val, idx, l))
        
        while min_heap:
            _, idx, top_list = heapq.heappop(min_heap)
            curr.next = top_list
            curr = top_list
            if top_list.next:
                heapq.heappush(min_heap, (top_list.next.val, idx, top_list.next))
        
        return dummy.next
        