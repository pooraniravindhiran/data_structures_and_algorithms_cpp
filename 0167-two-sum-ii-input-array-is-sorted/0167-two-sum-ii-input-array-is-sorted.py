# TC- O(n)
# SC- O(1)

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        ptr1, ptr2 = 0, len(numbers)-1
        while(ptr1<ptr2):
            sum_ = numbers[ptr1]+numbers[ptr2]
            if sum_==target:
                return [ptr1+1, ptr2+1]
            elif sum_<target:
                ptr1 += 1
            else:
                ptr2 -= 1
