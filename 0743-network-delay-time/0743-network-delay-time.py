# TC- O(e) + O(elogv) + O(v) = O(elogv +v)
# SC- O(v+e) + O(v)+ O(v) = O(v+e)

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))

        def dijkstra(src):
            dist = [float('inf')]*(n+1)
            dist[src] = 0
            min_heap = [(0, src)]
            while min_heap:
                curr_dist, node = heapq.heappop(min_heap)
                if curr_dist>dist[node]:
                    continue
                
                for neigh, cost in graph[node]:
                    if (curr_dist+cost) <dist[neigh]:
                        dist[neigh] = curr_dist+cost
                        heapq.heappush(min_heap, (dist[neigh], neigh))
            return dist

        min_time_all = float('-inf')
        dist = dijkstra(k)
        for i in range(1, n+1):
            if i!=k:
                if dist[i]==float('inf'):
                    return -1
                min_time_all = max(dist[i], min_time_all)
        return min_time_all