# TC- O(1) for add and O(k) for count
# SC- O(k) where k is num of unique pts

class DetectSquares:

    def __init__(self):
        # allow duplicates
        # frequency lookup O(1)
        # dict is good so far
        self.points = defaultdict(int)

    def add(self, point: List[int]) -> None:
        x, y = point
        self.points[(x,y)] += 1

    def count(self, point: List[int]) -> int:
        x, y = point
        total_count = 0

        for curr_point, freq in self.points.items():
            curr_x, curr_y = curr_point

            # check its diagonal and other 2 points
            if curr_x==x and curr_y==y:
                continue
            if abs(curr_x-x)==abs(curr_y-y) and (curr_x, y) in self.points and (x, curr_y) in self.points:
                # print(total_count, curr_point)
                total_count += self.points[(curr_x, y)]*self.points[(x, curr_y)]*self.points[(curr_x, curr_y)]
            
        return total_count



# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)