class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        
        m, n = len(mat), len(mat[0])
        q = deque()
        dirs = [-1, 0, 1, 0, -1]
        visited = set()

        for i in range(m):
            for j in range(n):
                if mat[i][j]==0:
                    q.append((i, j, 0))
                    visited.add((i, j))
        
        while q:
            r, c, level = q.popleft()

            for d in range(len(dirs)-1):
                next_r = r+dirs[d]
                next_c = c+dirs[d+1]
                if 0<=next_r<m and 0<=next_c<n and (next_r, next_c) not in visited:
                    mat[next_r][next_c] = level+1
                    visited.add((next_r, next_c))
                    q.append((next_r, next_c, level+1))
        return mat

