# TC- O(v+e)
# SC- O(v+e)

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # the problem can be formulated into a directed graph and we need to ultimately find if there's a cycle or not
        adj_mat = defaultdict(list)
        for prereq in prerequisites:
            adj_mat[prereq[0]].append(prereq[1])
        
        state = [0]*numCourses # 0 = unvisited, 1 = visiting, 2 = done

        def has_cycle(n):
            if state[n]==2:
                return False
            elif state[n]==1:
                return True
            
            state[n]=1
            for neigh in adj_mat[n]:
                if has_cycle(neigh):
                    return True
            state[n]=2
            return False

        for n in range(numCourses):
            if state[n]==0:
                if has_cycle(n):
                    return False
        return True