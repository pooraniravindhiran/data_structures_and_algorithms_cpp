# SC- O(n)

class TimeMap:
    def __init__(self):
        self.key_map = defaultdict(list)

    # TC- O(1)
    def set(self, key: str, value: str, timestamp: int) -> None:
        self.key_map[key].append((timestamp, value))

    # TC- O(logn)
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.key_map:
            return ""
        
        res = ""
        arr = self.key_map[key]

        # do binary search on value list
        left, right = 0, len(arr)-1
        while left<=right:
            mid = left+(right-left)//2
            if arr[mid][0]>timestamp:
                right = mid-1
            else:
                res = arr[mid][1]
                left = mid+1
        return res


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)