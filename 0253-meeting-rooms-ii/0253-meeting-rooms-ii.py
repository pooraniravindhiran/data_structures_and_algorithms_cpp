class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        min_heap = []
        for i in range(len(intervals)):
            start, end = intervals[i]
            if(min_heap and start>=min_heap[0]):
                heapq.heappop(min_heap)
            heapq.heappush(min_heap, intervals[i][1])
        return len(min_heap)

