# TC- O(nlogn)
# SC- O(n)

class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums)%k!=0:
            return False
        
        count = Counter(nums) # for bookkeeping because removing from list is more expensive
        nums.sort()

        for num in nums:
            if count[num] == 0:
                continue
            for i in range(k):
                if count[num+i] ==0:
                    return False
                count[num+i] -= 1
        return True