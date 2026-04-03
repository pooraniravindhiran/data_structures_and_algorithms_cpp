# TC- O(log(mn))
# SC- O(1)

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # binary search through all elements
        rows, cols = len(matrix), len(matrix[0])
        high = (rows*cols)-1
        low = 0

        while(low<=high):
            mid = low + (high-low)//2
            r = mid//cols
            c = mid%cols
            if target==matrix[r][c]:
                return True
            elif target<matrix[r][c]:
                high = mid-1
            elif target>matrix[r][c]:
                low = mid+1

        return False
        