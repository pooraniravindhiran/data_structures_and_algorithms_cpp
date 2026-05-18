# TC- O(nlogn+qlogq)
# SC- O(n+q)

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        
        ans = [-1]*len(queries)

        # sort intervals by start
        intervals.sort()

        # sort queries but also keep their indices
        sorted_queries = []
        for idx, query in enumerate(queries):
            sorted_queries.append((query, idx))
        sorted_queries.sort()

        # use min heap to store interval size and end time
        min_heap = []
        i = 0
        for query, idx in sorted_queries:
            # append
            while(i<len(intervals) and intervals[i][0]<=query):
                heapq.heappush(min_heap, (intervals[i][1]-intervals[i][0]+1, intervals[i][1]))
                i += 1

            # remove 
            while min_heap and min_heap[0][1]<query:
                heapq.heappop(min_heap)

            # pick top
            smallest_size = min_heap[0][0] if min_heap else -1

            # update ans
            if smallest_size!=-1:
                ans[idx] = smallest_size
        return ans