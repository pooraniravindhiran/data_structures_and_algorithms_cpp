# TC- O(nlogn)
# SC- O(n)

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort()

        min_heap = []

        for i in range(len(intervals)):
            if(not min_heap or intervals[i][0]<min_heap[0]):
                heapq.heappush(min_heap, intervals[i][1])
            else:
                heapq.heappop(min_heap)
                heapq.heappush(min_heap, intervals[i][1])
        
        return len(min_heap)
        