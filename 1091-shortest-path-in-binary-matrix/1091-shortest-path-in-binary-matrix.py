# TC-
# SC-

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # shortest clear path - use BFS
        # source and destination are given
        # 8 directionally connected
        # 1 is obstacle

        n = len(grid)
        if grid[0][0]==1 or grid[n-1][n-1]==1:
            return -1

        def bfs(src):
            q = deque()
            q.append((src, 1))
            grid[src[0]][src[1]] = 1
            neighbors = [[-1, 0], [1, 0], [0, -1], [0, 1], [-1, -1], [1, 1], [-1, 1], [1, -1]]

            while q:
                (r, c), level = q.popleft()

                if (r,c)==dst:
                    return level

                for neigh in neighbors:
                    next_r = r+neigh[0]
                    next_c = c+neigh[1]
                    if 0<=next_r<n and 0<=next_c<n and grid[next_r][next_c]==0:
                        grid[next_r][next_c] = 1
                        q.append(((next_r, next_c), level+1))
            return -1
                
        src, dst = (0,0), (n-1, n-1)
        path_len = bfs(src)
        return path_len