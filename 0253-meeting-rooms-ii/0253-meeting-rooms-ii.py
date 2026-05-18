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
        max_rooms = 0

        for interval in intervals:
            while min_heap and interval[0]>=min_heap[0]: # if because one new meeting can use only one new room
                heapq.heappop(min_heap)

            heapq.heappush(min_heap, interval[1])
            max_rooms = max(max_rooms, len(min_heap))
        return max_rooms