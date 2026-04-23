# prefix sum and binary search
# SC- O(n)
# TC- O(n)

class Solution:

    def __init__(self, w: List[int]):
        self.prefix_sums = []
        prefix_sum = 0
        for weight in w:
            prefix_sum += weight
            self.prefix_sums.append(prefix_sum)

    def binary_search(self, target) -> int:
        low = 0
        high = len(self.prefix_sums)-1

        while(low<high):
            mid = low + (high-low)//2
            if(self.prefix_sums[mid]<target):
                low = mid+1
            else:
                high = mid
        return low

    def pickIndex(self) -> int:
        target = random.randint(1, self.prefix_sums[-1])
        return self.binary_search(target)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()