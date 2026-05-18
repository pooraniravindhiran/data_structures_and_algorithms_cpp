# TC- O(nlogn)
# SC- O(n)

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
        # sort by start
        # while start>=top of heap, pop 
        # add it to heap
        # len of heap

        min_heap = []
        intervals.sort()

        for interval in intervals:
            if min_heap and interval[0]>=min_heap[0]:
                heapq.heappop(min_heap)

            heapq.heappush(min_heap, interval[1])
        return len(min_heap)