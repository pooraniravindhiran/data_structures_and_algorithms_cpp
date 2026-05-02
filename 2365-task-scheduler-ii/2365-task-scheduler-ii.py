# TC- O(n)
# SC- O(k)

class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        time = 0
        next_available = {}

        for task in tasks:
            if task in next_available and time<next_available[task]:
                time = next_available[task]
            time += 1
            next_available[task] = time+space
        return time