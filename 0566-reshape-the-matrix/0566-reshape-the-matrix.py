# TC- O(mn)
# SC- O(1)

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        if (r*c) != (rows*cols):
            return mat

        ans = [[0]*c for _ in range(r)]
        old_i, old_j = 0, 0
        for new_i in range(r):
            for new_j in range(c):
                ans[new_i][new_j] = mat[old_i][old_j]
                if old_j<cols-1:
                    old_j+=1
                else:
                    old_i+=1
                    old_j=0
        return ans