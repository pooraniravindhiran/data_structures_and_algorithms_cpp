# TC- O(mn*mn)
# SC- O(mn)

class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dist = [[0]*n for _ in range(m)]
        num_reachable = [[0]*n for _ in range(m)]
        num_buildings = 0

        def bfs(i, j):
            visited = [[False]*n for _ in range(m)]
            q = deque()
            q.append((i, j, 0))
            visited[i][j]=True
            dirs = [-1,0,1,0,-1]
            while q:
                r, c, level = q.popleft()

                for d in range(len(dirs)-1):
                    next_r = r+dirs[d]
                    next_c = c+dirs[d+1]

                    if 0<=next_r<m and 0<=next_c<n and grid[next_r][next_c]==0 and visited[next_r][next_c]==False:
                        visited[next_r][next_c]=True
                        dist[next_r][next_c] += level+1
                        q.append((next_r, next_c, level+1))
                        num_reachable[next_r][next_c] +=1

        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    num_buildings += 1
                    bfs(i, j)
        
        shortest_dist = float('inf')
        for i in range(m):
            for j in range(n):
                if num_reachable[i][j]==num_buildings:
                    shortest_dist = min(shortest_dist, dist[i][j])
        
        return -1 if shortest_dist==float('inf') else shortest_dist



                    