# SC- O(n) where n is num_pts added already

class DetectSquares:

    def __init__(self):
        self.counter = defaultdict(int)

    def add(self, point: List[int]) -> None:
        # TC- O(1)
        x, y = point
        self.counter[(x,y)] +=1

    def count(self, point: List[int]) -> int:
        # TC- O(n)
        x, y = point
        res = 0
        
        for (px,py), cnt in list(self.counter.items()):
            
            # if not diagonal, proceed
            if(px==x or py==y or abs(px-x)!=abs(py-y)):
                continue
            
            res += (cnt * self.counter[(x, py)] * self.counter[(px, y)])
        return res


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)