# SC- O(n)
class LRUCache:

    def __init__(self, capacity: int):
        # dict to store key and value
        # deque instead of heap due to O(1)
        self.capacity = capacity
        self.dict = {}
        self.order = deque()

    def get(self, key: int) -> int:
        # TC- O(n)
        # return val or -1
        if key not in self.dict:
            return -1
        
        # make it recent
        self.order.remove(key)
        self.order.append(key)

        return self.dict[key]

    def put(self, key: int, value: int) -> None:
        # TC- O(n)
        if key in self.dict:
            # update key in dict
            self.dict[key] = value

            # update order
            self.order.remove(key)
            self.order.append(key)

        else:

            # prune dict and order
            if len(self.order)>=self.capacity:
                key_to_remove = self.order.popleft()
                self.dict.pop(key_to_remove)

            self.dict[key] = value
            self.order.append(key)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)