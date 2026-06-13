# TC- O(nlogn)
# SC- O(n)

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        
        intervals.sort(key=lambda x:(x[0], -x[1]))

        ans = 1
        end = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][1]>end:
                ans += 1
                end = intervals[i][1]
            
        return ans