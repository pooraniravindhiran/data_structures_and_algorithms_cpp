# TC- O(nlogn)
# SC- O(n)

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # min num of intervals to remove, 
        # max num of intervals added
        # sort by end, pick shortest end always. if tie, then remove either- doesn't matter
        
        min_to_remove = 0

        intervals.sort(key=lambda x:x[1])
        end = intervals[0][1]

        for i in range(1, len(intervals)):
            start = intervals[i][0]
            if start<end:
                min_to_remove += 1
            else:
                end = intervals[i][1]
        
        return min_to_remove

            