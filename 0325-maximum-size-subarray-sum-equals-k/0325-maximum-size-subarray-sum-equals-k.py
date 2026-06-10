# TC- O(n)
# SC- O(n)

class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        ans = 0
        prefixsum_map = {}
        
        for i in range(len(nums)):
            
            prefix_sum += nums[i]
            
            if prefix_sum == k:
                ans = max(ans, i+1)
                
            if prefix_sum-k in prefixsum_map:
                ans = max(ans, i-prefixsum_map[prefix_sum-k])
            
            if prefix_sum not in prefixsum_map:
                prefixsum_map[prefix_sum] = i
            
        return ans