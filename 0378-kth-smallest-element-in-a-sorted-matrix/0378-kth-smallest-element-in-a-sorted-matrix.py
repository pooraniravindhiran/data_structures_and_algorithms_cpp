# if k is small, we can go with priority queue approach
# generally better approach is binary search

# TC- O(nlog(max-min))
# SC- O(1)
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)

        def count_less_than_equal(mid):
            # take top-right or left bottom as ref for efficient counting
            count = 0
            r, c = 0, n-1
            while c>=0 and r<n:
                if(matrix[r][c]<=mid):
                    count += c+1
                    r += 1
                else:
                    c -= 1
            return count

        # do binary search on values and not indices because the matrix does not give a sorted array when flattened
        left, right = matrix[0][0], matrix[-1][-1]
        while(left<right):
            mid = left + (right-left)//2
            if count_less_than_equal(mid)<k:
                left = mid+1
            else:
                right = mid
        return left
