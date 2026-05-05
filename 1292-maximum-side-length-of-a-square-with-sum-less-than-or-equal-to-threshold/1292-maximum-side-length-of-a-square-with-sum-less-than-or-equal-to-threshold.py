# TC- O(mn + mnlog(min(m,n)))
# SC- O(mn)

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        # we need to find sum of any square in O(1) so compute prefix sum
        rows = len(mat)
        cols = len(mat[0])
        prefix_sum = [[0]*(cols+1) for _ in range(rows+1)]
        for row in range(1, rows+1):
            for col in range(1, cols+1):
                prefix_sum[row][col] = mat[row-1][col-1] + prefix_sum[row-1][col]+ prefix_sum[row][col-1] -prefix_sum[row-1][col-1]

        def satisfies(k):
            # checks to see if there is atleast 1 square of side k whose sum<=threshold
            # topleft corner can go from 0 to rows-k+1
            for i in range(rows-k+1):
                for j in range(cols-k+1):
                    total = prefix_sum[i+k][j+k] - prefix_sum[i][j+k]- prefix_sum[i+k][j]+ prefix_sum[i][j]
                    if total<=threshold:
                        return True
            return False

        left, right = 0, min(rows, cols)
        while(left<right):
            mid = left + (right-left+1)//2
            if satisfies(mid):
                left = mid
            else:
                right = mid-1
        return left