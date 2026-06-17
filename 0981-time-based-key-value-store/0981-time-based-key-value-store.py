class TimeMap:

    def __init__(self):
        
        # key - multiple values based on ts
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.map or len(self.map[key])==0:
            return ""
        lst = self.map[key]
        if lst:
            left, right = 0, len(lst)-1
            ans = ""
            while left<=right:
                mid = left+(right-left)//2
                if lst[mid][0]>timestamp:
                    right = mid-1
                else:
                    ans = lst[mid][1]
                    left = mid+1
            return ans
        else:
            return ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)