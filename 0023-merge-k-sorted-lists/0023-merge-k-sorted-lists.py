# TC- O(Nlogk)
# SC- O(k)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = []
        
        # initialize heap with first element of each list
        for i, node in enumerate(lists):
            if node:
                min_heap.append((node.val, i, node)) # adding i so that heap comparison can use this if vals are equal
        heapq.heapify(min_heap)

        dummy = ListNode()
        curr = dummy
        
        while min_heap:
            val, i, node = heapq.heappop(min_heap)
            curr.next = node
            curr = curr.next
            lists[i] = lists[i].next
            if(lists[i]):
                heapq.heappush(min_heap, (lists[i].val, i, lists[i]))

        return dummy.next