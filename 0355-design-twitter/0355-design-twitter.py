# SC- O(u*t)

class Twitter:

    def __init__(self):
        self.following = defaultdict(set) # userId -> set of followees
        self.tweets = defaultdict(list)   #userId -> list of (tweetId, timestamp)
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        # TC- O(1)
        self.time += 1
        self.tweets[userId].append((self.time, tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        # TC- O(ulogu)
        res = []
        max_heap = []

        # user should follow themselves
        self.follow(userId, userId)

        # Put latest tweet of each followee onto the heap
        for followee in self.following[userId]:
            if followee in self.tweets:
                idx = len(self.tweets[followee])-1
                time, tweetId = self.tweets[followee][idx]
                heapq.heappush(max_heap, [-time, tweetId, followee, idx])

        # Now do the sorting and pull 10 latest tweets
        while(max_heap and len(res)<10):
            time, tweetId, followee, idx = heapq.heappop(max_heap)
            res.append(tweetId)

            # push the next tweet from same user
            if idx>0:
                next_time, next_tweetId = self.tweets[followee][idx-1]
                heapq.heappush(max_heap, [-next_time, next_tweetId, followee, idx-1])

        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        # TC- O(1)
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        # TC- O(1)
        self.following[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)