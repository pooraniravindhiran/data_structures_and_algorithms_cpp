# TC- O(n)
# SC- O(n)

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Count the freq of each element, then put it in a minheap sorted by freq, limit the minheap size by k and return the heap.

        freq_map = Counter(nums)

        min_heap = []
        for num, freq in freq_map.items():
            heapq.heappush(min_heap, (freq, num))
            if len(min_heap)>k:
                heapq.heappop(min_heap)
        
        ans = [num for (freq, num) in min_heap]
        return ans

