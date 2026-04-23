# TC- O(1)
# SC- O(m) where m is number of unique messages

class Logger:

    def __init__(self):
        self.last_seen = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.last_seen:
            self.last_seen[message] = timestamp
            return True
        else:
            if timestamp-self.last_seen[message]>=10:
                self.last_seen[message] = timestamp
                return True
            else:
                return False

# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)