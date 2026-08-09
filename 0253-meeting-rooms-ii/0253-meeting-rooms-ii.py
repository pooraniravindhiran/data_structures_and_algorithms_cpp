class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        min_heap = []
        intervals.sort()

        for interval in intervals:
            if not min_heap:
                heapq.heappush(min_heap, interval[1])
            else:
                if interval[0]>=min_heap[0]:
                    heapq.heappop(min_heap)
                    heapq.heappush(min_heap, interval[1])
                else:
                    heapq.heappush(min_heap, interval[1])
        return len(min_heap)
            