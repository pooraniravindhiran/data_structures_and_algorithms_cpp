
# TC- O((mn)^2)
# SC- O(mn)

class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        # BFS, num of buildings reachable from each land, total dist to reach all buildings that are reachable from each land
        # Need to do BFS, but that can happen sequentially/in parallel and from building/empty land. In general, num_buildings << num_emptylands. So doing BFS from buildings is better. Moreover, if we do BFS from each empty land, then there are more repetitive calculations too. Unlike wallsandgates problem where we need to find the nearest dist, we need to find the total dist here- so we do BFS sequentially from each building.
        
        rows, cols = len(grid), len(grid[0])
        num_reachable = [[0]*cols for _ in range(rows)]
        dist = [[0]*cols for _ in range(rows)]

        def bfs(r, c):
            visited = [[0]*cols for _ in range(rows)]
            q = deque()
            q.append((r, c, 0))
            dirs = [-1, 0, 1, 0, -1]
        
            while q:
                curr_r, curr_c, level = q.popleft()
                for d in range(len(dirs)-1):
                    next_r = curr_r+dirs[d]
                    next_c = curr_c+dirs[d+1]
                    if 0<=next_r<rows and 0<=next_c<cols and visited[next_r][next_c]==False and grid[next_r][next_c]==0:
                        visited[next_r][next_c] = True
                        dist[next_r][next_c] += level+1
                        num_reachable[next_r][next_c] += 1
                        q.append((next_r, next_c, level+1))

        # start bfs from every building
        total_buildings = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]==1:
                    total_buildings += 1
                    bfs(i, j)

        # check 
        shortest_total_dist = float('inf')
        for i in range(rows):
            for j in range(cols):
                if num_reachable[i][j] == total_buildings:
                    shortest_total_dist = min(shortest_total_dist, dist[i][j])

        if shortest_total_dist == float('inf'):
            return -1
        else:
            return shortest_total_dist
      