class Twitter {
private:
    int t;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;

public:
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> max_heap;
        vector<int> ans;

        follow(userId, userId);
        for(auto& followee:followees[userId]){
            if (!tweets[followee].empty()){
                int idx = tweets[followee].size()-1;
                max_heap.push({tweets[followee][idx].first, followee, tweets[followee][idx].second, idx});
            }
        }

        while(!max_heap.empty() and ans.size()<10){
            // get top 
            auto [time, user, tweetId, idx] = max_heap.top();

            // pop
            max_heap.pop();

            ans.push_back(tweetId);

            // dec that 
            idx = idx-1;

            // add it to heap
            if(idx>=0)
                max_heap.push({tweets[user][idx].first, user, tweets[user][idx].second, idx});
        }

        unfollow(userId, userId);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */