# SC- O(n)
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        # dict to store key and value
        # list due to O(1)
        self.capacity = capacity
        self.dict = {} #key, node

        # dummy head and tail
        self.head = Node(0,0)
        self.tail = Node(0,0)
        self.tail.prev = self.head
        self.head.next = self.tail

    def _remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def _add(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node
        
    def get(self, key: int) -> int:
        # TC- O(1)
        # return val or -1
        if key not in self.dict:
            return -1
        
        # make it recent
        node = self.dict[key]
        
        self._remove(node)
        self._add(node)

        return node.val

    def put(self, key: int, value: int) -> None:
        # TC- O(1)
        if key in self.dict:
            # update key in dict
            node = self.dict[key]
            self._remove(node)
            self.dict.pop(key)

        # prune dict and order
        if len(self.dict)>=self.capacity:
            key_to_remove = self.tail.prev.key
            self._remove(self.tail.prev)
            self.dict.pop(key_to_remove)

        node = Node(key, value)
        self.dict[key] = node
        self._add(node)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

# # SC- O(n)
# class LRUCache:

#     def __init__(self, capacity: int):
#         # dict to store key and value
#         # deque instead of heap due to O(1)
#         self.capacity = capacity
#         self.dict = {}
#         self.order = deque()

#     def get(self, key: int) -> int:
#         # TC- O(n)
#         # return val or -1
#         if key not in self.dict:
#             return -1
        
#         # make it recent
#         self.order.remove(key)
#         self.order.append(key)

#         return self.dict[key]

#     def put(self, key: int, value: int) -> None:
#         # TC- O(n)
#         if key in self.dict:
#             # update key in dict
#             self.dict[key] = value

#             # update order
#             self.order.remove(key)
#             self.order.append(key)

#         else:

#             # prune dict and order
#             if len(self.order)>=self.capacity:
#                 key_to_remove = self.order.popleft()
#                 self.dict.pop(key_to_remove)

#             self.dict[key] = value
#             self.order.append(key)

# # Your LRUCache object will be instantiated and called as such:
# # obj = LRUCache(capacity)
# # param_1 = obj.get(key)
# # obj.put(key,value)