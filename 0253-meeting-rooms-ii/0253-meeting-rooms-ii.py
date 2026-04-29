# TC- O(nlogn)
# SC- O(n)

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:x[0])
        min_rooms = []
        for interval in intervals:
            start, end = interval
            if min_rooms and start>=min_rooms[0]:
                heapq.heappop(min_rooms)
            heapq.heappush(min_rooms, end)
            
        return len(min_rooms)