class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        num_fresh = 0
        q = deque()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==1:
                    num_fresh += 1
                if grid[r][c]==2:
                    q.append((r, c))
        
        mins = 0
        while(q and num_fresh>0):
            curr_size = len(q)
            for i in range(curr_size):
                curr_r, curr_c = q.popleft()
                dirs = [-1, 0, 1, 0, -1]
                for d in range(len(dirs)-1):
                    next_r = curr_r+dirs[d]
                    next_c = curr_c+dirs[d+1]
                    if next_r>=0 and next_r<rows and next_c>=0 and next_c<cols and grid[next_r][next_c]==1:
                        grid[next_r][next_c] = 2
                        num_fresh -= 1
                        q.append((next_r, next_c))

            mins +=1
        
        if num_fresh>0:
            return -1
        
        return mins