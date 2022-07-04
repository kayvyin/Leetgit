struct Compare{
    bool operator()(pair<int,int> x, pair<int, int> y){
        return x.first < y.first;
    }
};
class Twitter {
private:
    int time;
    int max_feed;
    priority_queue<vector<int>> feed;
    unordered_map<int, unordered_set<int>> follow_hash;
public:
    Twitter() {
        max_feed = 10;
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        feed.push({time++, userId, tweetId});           
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> ref = feed;
        while(!ref.empty() && ans.size() < max_feed){
            auto popped = ref.top();
            if(popped[1] == userId || follow_hash[userId].find(popped[1]) != follow_hash[userId].end()){
                ans.push_back(popped[2]);
            }
            ref.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follow_hash[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_hash[followerId].erase(followeeId);
    
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