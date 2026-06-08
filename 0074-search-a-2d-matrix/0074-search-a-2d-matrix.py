# TC- O(logmn)
# SC- O(1)

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        # matrix if read in row major order is already sorted, so binary search

        m, n = len(matrix), len(matrix[0])
        left, right = 0, m*n-1

        while(left<=right):
            
            mid = left + (right-left)//2
            r = mid // n
            c = mid % n

            if matrix[r][c]==target:
                return True
            
            elif target<matrix[r][c]:
                right = mid-1

            else:
                left = mid+1
        
        return False
            
