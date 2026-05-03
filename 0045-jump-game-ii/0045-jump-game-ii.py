# TC- O(n)
# SC- O(1)

# Greedy because at every point you're considering only the current jump and the final solution is based on these independent local choices. 
# From current position, you can jump upto farthest. But for each of the positions in this reach upto farthest, your jump count is 1. 

class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums)<=1:
            return 0
            
        current_end = 0
        farthest = 0
        jumps = 0
        for i, jump in enumerate(nums):
            farthest = max(farthest, i+jump)

            if i==current_end:
                jumps += 1
                current_end = farthest
                if current_end>=len(nums)-1:
                    break
        return jumps   