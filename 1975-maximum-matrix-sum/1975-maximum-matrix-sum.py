# TC- O(mn)
# SC- O(1)

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        # in every operation, total num of negative signs in matrix changes by 0, +2, -2. 
        # if we have even number of negative signs (even if not adjacent), somehow we can get them together and make everything positive. in that case, max sum = sum of abs value of all elements
        # if we have odd number of negative signs, there will always be one left. To maximize sum, we need to move this to the lowest element possible.

        count_neg = 0
        total_abs = 0
        min_val = float('inf')
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c]<0:
                    count_neg += 1
                min_val = min(abs(matrix[r][c]), min_val)
                total_abs += abs(matrix[r][c])

        
        if count_neg%2==0:
            return total_abs
        else:
            return total_abs - (2*min_val)