# TC- O(nlogn)
# SC- O(n)

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
        intervals.sort()
        min_heap = [] # heap stores end times of all active meetings
        max_rooms = 0
        for interval in intervals:
            while min_heap and interval[0]>=min_heap[0]:
                heapq.heappop(min_heap)
            heapq.heappush(min_heap, interval[1])
            max_rooms = max(max_rooms, len(min_heap))
        return max_rooms          