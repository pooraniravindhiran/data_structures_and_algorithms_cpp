# TC- O(E log(VK))
# SC- O(E+VK)

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        
        # directed weighted graph- edges given
        # src and dst given
        # do bfs- if levels<=k, update cost. else finally return -1

        adj_mat = defaultdict(list)
        for u, v, w in flights:
            adj_mat[u].append((v, w))

        q = []
        q.append((0, src, 0)) # cost so far, node, stops used

        # stores best cost for (node, stops)
        visited = {}

        while q:

            cost, node, stops_used = heapq.heappop(q)

            if node==dst:
                return cost
            
            if stops_used>k:
                continue
            
            if (node, stops_used) in visited and visited[(node, stops_used)] <= cost:
                continue

            visited[(node, stops_used)] = cost

            for nei, price in adj_mat[node]:
                heapq.heappush(q,(cost + price, nei, stops_used + 1))
        
        return -1