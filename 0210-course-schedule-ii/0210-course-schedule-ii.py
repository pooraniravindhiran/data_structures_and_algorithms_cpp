# TC- O(p+n)
# SC- O(p+n)

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj_mat = defaultdict(list)
        for prereq in prerequisites:
            adj_mat[prereq[1]].append(prereq[0])
        
        state= [0]*numCourses
        order = []
        
        def has_cycle(i):
            if state[i]==2:
                return False
            if state[i]==1:
                return True

            state[i]=1
            for c in adj_mat[i]:
                if has_cycle(c):
                    return True
            state[i]=2
            order.append(i)
            return False

        for i in range(numCourses):
            if state[i]==0:
                if has_cycle(i):
                    return []
        return order[::-1]