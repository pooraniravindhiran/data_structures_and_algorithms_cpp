# TC- O(n)
# SC- O(1)

# Greedy because at every point you're considering only the current jump and the final solution is based on these independent local choices.

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reach = 0
        for i, jump in enumerate(nums):
            if i>max_reach:
                return False
            max_reach = max(max_reach, i+jump)
        return True