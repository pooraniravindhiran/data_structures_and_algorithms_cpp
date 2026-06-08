# TC- O(logn)
# SC- O(1)

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        def leftmost_occ():
            left, right = 0, len(nums)-1
            ans = -1
            while(left<=right):
                mid = left+(right-left)//2

                if target==nums[mid]:
                    ans = mid
                    right = mid-1
                
                elif target<nums[mid]:
                    right = mid-1
                
                else:
                    left = mid+1

            return ans
        
        def rightmost_occ():
            left, right = 0, len(nums)-1
            ans = -1
            while(left<=right):
                mid = left+(right-left)//2

                if target==nums[mid]:
                    ans = mid
                    left = mid+1
                
                elif target<nums[mid]:
                    right = mid-1
                
                else:
                    left = mid+1

            return ans
        
        return [leftmost_occ(), rightmost_occ()]