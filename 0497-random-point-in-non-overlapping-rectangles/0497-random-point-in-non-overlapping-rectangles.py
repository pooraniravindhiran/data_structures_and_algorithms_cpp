# SC- O(n)
class Solution:
    # we want to select any point from any rect equally, meaning big rect has more points so effectively gets more probability. i.e we want weighted random selection. 

    def __init__(self, rects: List[List[int]]):
        # TC- O(n)
        self.rects = rects
        self.prefix_sum_areas = []
        self.total = 0

        for a,b,x,y in rects:
            area = (x-a+1)*(y-b+1)
            self.total += area
            self.prefix_sum_areas.append(self.total)

    def binary_search(self, target):
        left, right = 0, len(self.prefix_sum_areas)-1
        while left<right:
            mid = left + (right-left)//2
            if self.prefix_sum_areas[mid]<target:
                left = mid+1
            else:
                right = mid
        return left

    def pick(self) -> List[int]:
        # TC- O(logn)
        target = random.randint(1, self.total)
        idx = self.binary_search(target)
        a,b,x,y = self.rects[idx]
        prev_pts = self.prefix_sum_areas[idx-1] if idx>0 else 0
        offset = target-prev_pts-1 # 1 index to 0 index
        width = x-a+1
        return [a+offset%width, b+offset//width]

# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()