# TC- O(logn)
# SC- O(1)

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left = 0
        right = len(nums)-1

        while(left<=right):
            mid = left+(right-left)//2
            if nums[mid]==target:
                return True
            
            # if duplicate, then no useful info because we cant decide which side is sorted. so we just remove it
            elif nums[left]==nums[mid]==nums[right]:
                left +=1
                right-=1

            elif nums[left]<=nums[mid]: # left array is sorted
                if nums[left]<=target<nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
            else:
                if nums[mid]<target<=nums[right]:
                    left = mid+1
                else:
                    right = mid-1

        return False