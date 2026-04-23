# TC- O(n)
# SC- O(n)

class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        n = len(heights)
        potentially_visible = [] # monotonic decreasing stack representing potential people that can be seen. Top of stack is the immediate right person whom you can always see. Deeper in the stack are people whom you can potentially see.
        ans = [0 for _ in range(n)]

        for i in range(n-1, -1, -1):
            count = 0

            # calculate count
            while potentially_visible and heights[i] > potentially_visible[-1]:
                count += 1
                potentially_visible.pop()
            if potentially_visible:
                count += 1

            # update count
            ans[i] = count

            # update stack
            potentially_visible.append(heights[i])

        return ans