# TC- O(k log(min(k, m)))
# SC- O(min(k, m)) where m is len(nums1)

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        min_heap = []

        for i in range(min(k, len(nums1))):
            heapq.heappush(min_heap, (nums1[i]+nums2[0], i, 0))
        
        ans = []
        while min_heap and len(ans)<k:

            _, i, j = heapq.heappop(min_heap)
            ans.append([nums1[i], nums2[j]])

            if j+1<len(nums2):
                heapq.heappush(min_heap, (nums1[i]+nums2[j+1], i, j+1))

        return ans
