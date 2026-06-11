# TC-
# SC- O(v+e)

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # check if cycle exists - not parent but already visited

        visited = set()
        cycle_nodes = []

        # create adj matrix
        adj_mat = defaultdict(list)
        for edge in edges:
            adj_mat[edge[0]].append(edge[1])
            adj_mat[edge[1]].append(edge[0])
        
        path_idx = {}  # node -> index in path

        def dfs(node, parent, path):
            visited.add(node)
            path_idx[node] = len(path)
            path.append(node)
            
            for neigh in adj_mat[node]:
                if neigh not in visited:
                    if dfs(neigh, node, path):
                        return True
                elif neigh != parent:
                    idx = path_idx[neigh]  # O(1) instead of O(n)
                    cycle_nodes.extend(path[idx:])
                    return True
            
            path.pop()
            del path_idx[node]
            return False

        dfs(1, -1, [])

        # return the LAST edge in the input that has both nodes in cycle_nodes
        for u, v in reversed(edges):
            if u in cycle_nodes and v in cycle_nodes:
                return [u, v]