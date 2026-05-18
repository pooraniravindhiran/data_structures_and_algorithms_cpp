# TC- O(e) = O(n)
# SC- O(v) = O(n)

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        
        # initialize parent(leader of group) - initially each node is its own leader
        parent = {}
        for u, v in edges:
            if u not in parent:
                parent[u] = u
            if v not in parent:
                parent[v] = v
        
        def find(a):
            if parent[a]==a:
                return a
            return find(parent[a])

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa == pb:
                return False
            parent[pb] = pa
            return True

        for u, v in edges:
            if not union(u, v):
                return [u, v]