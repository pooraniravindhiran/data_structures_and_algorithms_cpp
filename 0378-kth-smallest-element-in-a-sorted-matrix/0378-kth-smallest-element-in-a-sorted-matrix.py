# SC- O(1)
# TC- O(n * log(max-min))

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)

        def count_less_equal(mid):
            count = 0
            r, c = n-1, 0
            while(r>=0 and c<n):
                if(matrix[r][c]<=mid):
                    count += r+1
                    c +=1
                else:
                    r -= 1
            return count

        low, high = matrix[0][0], matrix[-1][-1]
        while(low<high):
            mid = (low+high)//2
            if count_less_equal(mid)<k:
                low = mid+1
            else:
                high = mid

        return low
