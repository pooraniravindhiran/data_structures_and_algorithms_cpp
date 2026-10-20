class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets; // user_id, tweet ids
    unordered_map<int, unordered_set<int>> following;
    int t;

public:
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // TC- O(1)
        tweets[userId].push_back({t, tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // TC- O(ulogu)
        vector<int> ans;
        following[userId].insert(userId);

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, less<tuple<int, int, int, int>>> max_heap;
        for(int user: following[userId]){
            if (tweets[user].empty())
                continue;
            int idx = tweets[user].size()-1;
            auto latest_tweet = tweets[user][idx];
            max_heap.push({latest_tweet.first, latest_tweet.second, idx, user});
        }

        while(!max_heap.empty()){
            if(ans.size()==10)
                break;
            
            auto [time, tweet_id, idx, user] = max_heap.top();
            max_heap.pop();
            ans.push_back(tweet_id);

            if(idx>0){
                idx --;
                max_heap.push({tweets[user][idx].first, tweets[user][idx].second, idx, user});
            }
        }
        following[userId].erase(userId);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        // TC- O(1)
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // TC- O(1)
        following[followerId].erase(followeeId);
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