# TC- O(mn)
# SC- O(mn)

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        n = len(grid)
        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1), (-1, 1), (1, -1), (-1, -1), (1, 1)]
        src, dst = (0, 0), (n-1, n-1)

        if grid[0][0] ==1 or grid[n-1][n-1]==1:
            return -1

        def bfs(src, dst):
            q = deque()
            q.append((src, 1))
            grid[0][0] = 1

            while q:
                (r, c), dist = q.popleft()
                # print(r, c, dist)
                if(r,c)==dst:
                    return dist
                
                for d in dirs:
                    next_r = r+d[0]
                    next_c = c+d[1]
                    if 0<=next_r<n and 0<=next_c<n and grid[next_r][next_c]==0:
                        grid[next_r][next_c] = 1
                        q.append(((next_r, next_c), dist+1))
            return -1 

        min_dist = bfs(src, dst)

        return min_dist