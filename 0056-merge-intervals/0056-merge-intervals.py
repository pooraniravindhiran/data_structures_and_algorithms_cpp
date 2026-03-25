# TC- O(nlogn)
# SC- O(n)

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        i = 0
        intervals.sort()
        while i<len(intervals):
            start = intervals[i][0]
            end = intervals[i][1]
            while(i+1<len(intervals) and intervals[i+1][0]<=end):
                end = max(end, intervals[i+1][1])
                i += 1
            ans.append([start, end])
            i += 1

        return ans