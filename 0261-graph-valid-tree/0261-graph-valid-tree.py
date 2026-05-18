# TC- O(V+E)
# SC- O(V+E)

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # valid tree if graph with no cycles, n-1 edges and is fully connected.

        if len(edges)!=n-1:
            return False

        # create adj mat
        adj_mat = defaultdict(list)
        for edge in edges:
            adj_mat[edge[0]].append(edge[1])
            adj_mat[edge[1]].append(edge[0])

        visited = set()
        def has_cycle(node, parent):
            visited.add(node)
            for nei in adj_mat[node]:
                if nei==parent:
                    continue
                elif nei in visited:
                    return True
                elif has_cycle(nei, node):
                    return True
            return False

        if has_cycle(0, -1):
            return False

        return len(visited) == n
