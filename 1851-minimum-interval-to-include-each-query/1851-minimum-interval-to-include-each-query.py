# TC- O(nlogn+qlogq)
# SC- O(n+q)

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        # sort intervals by start
        intervals.sort()

        # sort queries but also keep their indices
        sorted_queries = [(q, i) for i,q in enumerate(queries)]
        sorted_queries.sort()

        # use min heap to store interval size and end time
        min_heap = []
        ans = [-1]*len(queries)
        i = 0
        for query, query_idx in sorted_queries:

            # add intervals to min heap if start<=query
            while(i<len(intervals) and intervals[i][0]<=query):
                heapq.heappush(min_heap, (intervals[i][1]-intervals[i][0]+1, intervals[i][1]))
                i += 1
            
            # remove intervals from min_heap if end<query
            while(min_heap and min_heap[0][1]<query):
                heapq.heappop(min_heap)
            
            if min_heap:
                ans[query_idx] = min_heap[0][0]
        
        return ans
            

