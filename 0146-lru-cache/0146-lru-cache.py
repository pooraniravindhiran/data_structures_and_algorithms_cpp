class Node:
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.prev = None
        self.next = None

# SC- O(capacity)
class LRUCache:
    def __init__(self, capacity: int):
        # O(1) for lookup of key
        # O(1) for removal of first key
        # O(1) for moving arbitrary key to beginning
        # for these, use dict and dll
        self.capacity = capacity
        self.dict = {}
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
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
        if key in self.dict:
            node = self.dict[key]
            # move node to front
            self._remove(node)
            self._add(node)
            return node.val
        return -1

    def put(self, key: int, value: int) -> None:
        # TC- O(1)
        if key in self.dict:
            node = self.dict[key]
            node.val = value
            self._remove(node)
            self._add(node)
        else:
            node = Node(key, value)
            self.dict[key] = node
            self._add(node)

        if len(self.dict)>self.capacity:
            if self.tail.prev!=self.head:
                lru = self.tail.prev
                self._remove(self.tail.prev)
                del self.dict[lru.key]

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)