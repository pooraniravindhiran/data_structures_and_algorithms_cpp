# TC- O(n+e)
# SC- (n+e)

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        
        adj_mat = defaultdict(list)
        for edge in edges:
            adj_mat[edge[0]].append(edge[1])
            adj_mat[edge[1]].append(edge[0])
        
        num = 0
        visited = set()

        def dfs(i):
            visited.add(i)
            for neigh in adj_mat[i]:
                if neigh not in visited:
                    dfs(neigh)

        for i in range(n):
            if i not in visited:
                num += 1
                dfs(i)
        return num