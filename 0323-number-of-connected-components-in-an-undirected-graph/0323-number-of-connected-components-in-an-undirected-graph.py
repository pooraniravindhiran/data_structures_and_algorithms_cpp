# TC- O(v+e)
# SC- O(e+v)

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj_mat = defaultdict(list)
        for edge in edges:
            adj_mat[edge[0]].append(edge[1])
            adj_mat[edge[1]].append(edge[0])
        
        ans = 0
        visited = set()

        def dfs(node):
            visited.add(node)
            for nei in adj_mat[node]:
                if nei not in visited:
                    dfs(nei)

        for i in range(n):
            if i not in visited:
                ans += 1
                dfs(i)
        return ans