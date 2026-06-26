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

# Variations
# 1. Memory Growth Problem- If millions of unique messages arrive, hashmap grows forever. We only care about last 10 seconds. So remove old messages.
# Code
# from collections import deque
# class Logger:

#     def __init__(self):
#         self.q = deque()
#         self.last_seen = {}

#     def shouldPrintMessage(self, timestamp, message):

#         # remove expired messages
#         while self.q and self.q[0][0] <= timestamp - 10:
#             old_time, old_msg = self.q.popleft()

#             # avoid deleting newer occurrence
#             if self.last_seen.get(old_msg) == old_time:
#                 del self.last_seen[old_msg]

#         # if message already active
#         if message in self.last_seen:
#             return False

#         # insert new message
#         self.last_seen[message] = timestamp
#         self.q.append((timestamp, message))

#         return True
# Why This Is Better: Memory becomes O(messages within last 10 sec), instead of O(all messages ever).
# 2. Different Rate Limits Per Message Type

# Now:

# ERROR -> 60 sec
# INFO -> 5 sec
# DEBUG -> 1 sec
# Idea

# Need:

# message_type -> cooldown
# Code
# class Logger:

#     def __init__(self):

#         self.last_seen = {}

#         self.cooldowns = {
#             "ERROR": 60,
#             "INFO": 5,
#             "DEBUG": 1
#         }

#     def shouldPrintMessage(self, timestamp, msg_type, message):

#         cooldown = self.cooldowns[msg_type]

#         if message not in self.last_seen:
#             self.last_seen[message] = timestamp
#             return True

#         if timestamp - self.last_seen[message] >= cooldown:
#             self.last_seen[message] = timestamp
#             return True

#         return False

# 5. Sliding Window Instead of Fixed Cooldown

# Original:

# Only once every 10 sec

# New:

# Allow at most 5 logs within rolling 10 sec window

# This is MUCH more interesting.

# Example

# Allowed:

# 1,2,3,4,5

# At timestamp 6:

# reject

# At timestamp 12:

# timestamp 1 expires
# accept
# Key Insight

# Need all recent timestamps.

# Not just last one.

# Use:

# message -> deque of timestamps
# Code
# from collections import defaultdict, deque

# class Logger:

#     def __init__(self):

#         self.logs = defaultdict(deque)

#     def shouldPrintMessage(self, timestamp, message):

#         q = self.logs[message]

#         # remove old timestamps
#         while q and q[0] <= timestamp - 10:
#             q.popleft()

#         # already 5 logs in window
#         if len(q) >= 5:
#             return False

#         q.append(timestamp)

#         return True
