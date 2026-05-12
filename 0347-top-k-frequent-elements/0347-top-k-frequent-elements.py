# TC- O(n)
# SC- O(n)

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Max freq can be just n, so create buckets of freq 1 to n, append each num. Then iterate and return res.

        freq_buckets = defaultdict(list)
        counter = Counter(nums)
        for (num, freq) in counter.items():
            freq_buckets[freq].append(num)

        ans = []
        for freq in range(len(nums), 0, -1):
            for num in freq_buckets[freq]:
               ans.append(num)
            if len(ans)==k:
                return ans
        
        return ans

# # TC- O(n+mlogk)
# # SC- O(m+k)

# class Solution:
#     def topKFrequent(self, nums: List[int], k: int) -> List[int]:
#         # Count the freq of each element, then put it in a minheap sorted by freq, limit the minheap size by k and return the heap.

#         freq_map = Counter(nums)

#         min_heap = []
#         for num, freq in freq_map.items():
#             heapq.heappush(min_heap, (freq, num))
#             if len(min_heap)>k:
#                 heapq.heappop(min_heap)
        
#         ans = [num for (freq, num) in min_heap]
#         return ans