# TC- O(logn)
# SC- O(1)

class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        left = 0
        right = len(nums)-1

        # if not rotated
        if nums[left]<nums[right]:
            return nums[0]
        
        # if rotated
        while(left<right):
            mid = left+ (right-left)//2
            if nums[mid]>nums[mid+1]: # 3 4 5 1 2
                return nums[mid+1]
            
            elif nums[mid]<nums[mid-1]: # 4 5 1 2 3
                return nums[mid]

            elif nums[left]>nums[mid]: # 5 1 2 3 4
                right = mid
            
            else:   # 2 3 4 5 1
                left = mid+1