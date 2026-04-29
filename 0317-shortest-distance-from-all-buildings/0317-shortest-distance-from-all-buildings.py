# TC- O((mn)^2)
# SC- O(mn)

class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        # Need to do BFS, but that can happen sequentially/in parallel and from building/empty land. In general, num_buildings << num_emptylands. So doing BFS from buildings is better. Moreover, if we do BFS from each empty land, then there are more repetitive calculations too. Unlike wallsandgates problem where we need to find the nearest dist, we need to find the total dist here- so we do BFS sequentially from each building.

        rows = len(grid)
        cols = len(grid[0])

        # Create dist, reach and visited matrices
        dist = [[0]*cols for _ in range(rows)]
        reach = [[0]*cols for _ in range(rows)]

        def bfs(r, c):
            q = deque()
            q.append((r, c, 0))
            visited = [[False]*cols for _ in range(rows)]
            visited[r][c] = True
            dirs = [-1, 0, 1, 0, -1]

            while(q):
                curr_r, curr_c, level = q.popleft()
                for d in range(len(dirs)-1):
                    next_r = curr_r + dirs[d]
                    next_c = curr_c + dirs[d+1]
                    if next_r>=0 and next_r<rows and next_c>=0 and next_c<cols and visited[next_r][next_c]==False and grid[next_r][next_c]==0:
                        dist[next_r][next_c] += level+1
                        visited[next_r][next_c] = True
                        reach[next_r][next_c] += 1
                        q.append((next_r, next_c, level+1))

        # start bfs from every building
        total_buildings = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==1:
                    total_buildings += 1
                    bfs(r, c)

        # iterate through dist and reach matrices
        shortest_total_dist = float('inf')
        for r in range(rows):
            for c in range(cols):
                if reach[r][c]==total_buildings:
                    shortest_total_dist = min(shortest_total_dist, dist[r][c])
        
        return shortest_total_dist if shortest_total_dist!=float('inf') else -1