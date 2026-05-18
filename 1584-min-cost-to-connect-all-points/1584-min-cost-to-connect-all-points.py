# TC- O(n^2)
# SC- O(n)

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # Find minimum spanning tree because it should not have cycle, it should be fully connected and it should be minimum cost
        
        # pick one node to add to mst in every outer iter.
        # pick the node by traversing through unvisited list and getting the node with min cost to any node in mst.
        # iterate through unvisited nodes and update each node's cheapest cost to the mst 
 
        n = len(points)
        min_cost = [float('inf')] * n
        min_cost[0] = 0
        visited = [False]*n
        total = 0

        for _ in range(n):

            u = -1
            for i in range(n):
                if not visited[i] and (u==-1 or min_cost[i]<min_cost[u]):
                    u = i
            
            visited[u] = True
            total += min_cost[u]

            x1, y1 = points[u]
            for v in range(n):
                if not visited[v]:
                    x2, y2 = points[v]
                    dist = abs(y2-y1)+abs(x2-x1)
                    if dist<min_cost[v]:
                        min_cost[v] = dist
                    
        return total

