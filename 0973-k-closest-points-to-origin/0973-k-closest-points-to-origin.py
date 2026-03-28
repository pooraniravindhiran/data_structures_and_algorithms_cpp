# TC- O(nlogk)
# SC- O(k)
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        max_heap = []
        for idx, point in enumerate(points):
            dist = point[0]*point[0]+point[1]*point[1]
            heapq.heappush(max_heap, (-dist, idx))
            if len(max_heap)>k:
                heapq.heappop(max_heap)

        return [points[idx] for (_, idx) in max_heap]