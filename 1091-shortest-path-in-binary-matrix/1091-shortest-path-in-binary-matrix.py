# TC- O(n^2)
# SC- O(n^2)

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # do bfs, track visited by making it 1
        n = len(grid)
        if grid[0][0]!=0 or grid[n-1][n-1]!=0:
            return -1
        if len(grid)==1:
            return 1
        
        src, dst = (0,0), (n-1, n-1)
        q = deque()
        q.append(src)
        grid[0][0] = 1
        dirs = [(-1,0), (1,0), (0,1), (0,-1), (-1,1), (-1,-1), (1,-1), (1,1)]
        dist = 1
        while q:
            q_size = len(q)
            dist += 1
            for _ in range(q_size):
                curr_r, curr_c = q[0]
                q.popleft()
                for d in dirs:
                    next_r = curr_r+d[0]
                    next_c = curr_c+d[1]
                    if (next_r, next_c) == dst:
                        return dist
                    if 0<=next_r<n and 0<=next_c<n and grid[next_r][next_c]==0:
                        q.append((next_r, next_c))
                        grid[next_r][next_c] = 1
        return -1
        

