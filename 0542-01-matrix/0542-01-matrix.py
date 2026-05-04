# TC- O(mn)
# SC- O(mn)

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        q = deque()
        visited = set()

        for r in range(rows):
            for c in range(cols):
                if mat[r][c]==0:
                    q.append((r,c, 0))
                    visited.add((r,c))
        
        while q:
            curr_r, curr_c, level = q.popleft()
            dirs = [-1, 0, 1, 0, -1]
            for d in range(len(dirs)-1):
                next_r = curr_r+dirs[d]
                next_c = curr_c+dirs[d+1]
                if 0<=next_r<rows and 0<=next_c<cols and (next_r, next_c) not in visited:
                    visited.add((next_r, next_c))
                    q.append((next_r, next_c, level+1))
                    mat[next_r][next_c] = level+1
        return mat