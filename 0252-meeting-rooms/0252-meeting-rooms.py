# TC- O(nlogn)
# SC- O(n)

class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()

        for i in range(1, len(intervals)):
            if(intervals[i][0]<intervals[i-1][1]):
                return False
        return True