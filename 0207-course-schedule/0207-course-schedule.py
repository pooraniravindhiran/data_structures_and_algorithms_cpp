# TC- O(V+E)
# SC- O(E+V)

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # create an adj matrix and for each course, do a traversal. If, at any point, you find a loop, then return False. Else, return True. the problem can be formulated into a directed graph and we need to ultimately find if there's a cycle or not

        adj_mat = defaultdict(list)
        for course, prereq in prerequisites:
            adj_mat[prereq].append(course)
        
        # 0 = unvisited, 1 = visiting, 2 = done
        state = [0]*numCourses

        def has_cycle(i):
            if state[i]==2:
                return False
            
            if state[i]==1:
                return True
            
            state[i] = 1
            for course in adj_mat[i]:
                if has_cycle(course):
                    return True

            state[i] = 2
            return False

        for i in range(numCourses):
            if state[i]==0 and has_cycle(i):
                    return False
        return True