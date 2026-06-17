# TC- O(mn)
# SC- O(mn)

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        m, n = len(grid), len(grid[0])
        dirs = [-1, 0, 1, 0, -1]
        fresh = 0
        q = deque()

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh += 1
                if grid[i][j] == 2:
                    q.append((i, j))
        # print(fresh)

        min_time = 0
        while q:
            q_size = len(q)
            anything_rotted = False
            for i in range(q_size):
                r, c = q.popleft()
                grid[r][c] = 0 #mark as visited

                for d in range(len(dirs)-1):
                    next_r, next_c = r+dirs[d], c+dirs[d+1]
                    if 0<=next_r<m and 0<=next_c<n and grid[next_r][next_c]==1:
                        fresh -= 1
                        grid[next_r][next_c] = 0
                        anything_rotted = True
                        q.append((next_r, next_c))
            if anything_rotted:
                min_time += 1

        # print(fresh)
        if fresh!=0:
            return -1
        
        return min_time
                