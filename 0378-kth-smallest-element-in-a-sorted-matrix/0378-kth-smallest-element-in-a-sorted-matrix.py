# if k is small, we can go with priority queue approach
# generally better approach is binary search

# TC- O(klogn)
# SC- O(n)
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)

        min_heap = []
        for i in range(min(n,k)):
            heapq.heappush(min_heap, (matrix[i][0], i, 0))
        num_pops = k-1

        while num_pops:
            num_pops -= 1
            val, r, c = heapq.heappop(min_heap)

            if c+1<n:
                heapq.heappush(min_heap, (matrix[r][c+1], r, c+1))

        return heapq.heappop(min_heap)[0]


# # TC- O(nlog(max-min))
# # SC- O(1)
# class Solution:
#     def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
#         n = len(matrix)

#         def count_less_than_equal(mid):
#             # take top-right or left bottom as ref for efficient counting
#             count = 0
#             r, c = 0, n-1
#             while c>=0 and r<n:
#                 if(matrix[r][c]<=mid):
#                     count += c+1
#                     r += 1
#                 else:
#                     c -= 1
#             return count

#         # do binary search on values and not indices because the matrix does not give a sorted array when flattened
#         left, right = matrix[0][0], matrix[-1][-1]
#         while(left<right):
#             mid = left + (right-left)//2
#             if count_less_than_equal(mid)<k:
#                 left = mid+1
#             else:
#                 right = mid
#         return left
