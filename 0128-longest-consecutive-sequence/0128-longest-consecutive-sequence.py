# TC- O(n)
# SC- O(n)

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        maxlen = 0

        # put nums into a set
        unique = set(nums)

        for num in unique:
            if num-1 not in unique: # seq starts here
                left = num
                right = num
                while(right+1 in unique):
                    right += 1
                maxlen = max(maxlen, right-left+1)
        
        return maxlen
