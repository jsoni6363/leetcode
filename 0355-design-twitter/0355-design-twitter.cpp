bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;  // higher time = newer tweet
}
class Twitter {
    // Global timestamp to maintain tweet order
    int time;

    // followMap[u] = set of users that u follows
    unordered_map<int, unordered_set<int>> followMap;

    // tweetMap[u] = list of (time, tweetId) posted by user u
    unordered_map<int, vector<pair<int, int>>> tweetMap;

public:
    // Constructor
    Twitter() {
        time = 0;
    }

    /*
     postTweet
     ----------
     User 'userId' posts a tweet with id 'tweetId'
     We store the tweet along with the current timestamp
    */
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time, tweetId});
        time++;  // increment global time
    }

    /*
     getNewsFeed
     ------------
     Returns the 10 most recent tweets visible to userId
     Includes:
       - user's own tweets
       - tweets from users they follow
    */
    vector<int> getNewsFeed(int userId) {

    // This will store (time, tweetId)
    vector<pair<int, int>> feed;

    // 1️⃣ Add user's own tweets
    for (int i = 0; i < tweetMap[userId].size(); i++) {
        feed.push_back(tweetMap[userId][i]);
    }

    // 2️⃣ Add tweets of users that this user follows
    for (int followeeId : followMap[userId]) {
        for (int i = 0; i < tweetMap[followeeId].size(); i++) {
            feed.push_back(tweetMap[followeeId][i]);
        }
    }

    // 3️⃣ Sort tweets by time (newest first)
    sort(feed.begin(), feed.end(), compare);

    // 4️⃣ Take first 10 tweet IDs
    vector<int> result;
    int limit = min(10, (int)feed.size());

    for (int i = 0; i < limit; i++) {
        result.push_back(feed[i].second);
    }

    return result;
}


    /*
     follow
     ------
     followerId starts following followeeId
     */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // can't follow self
        followMap[followerId].insert(followeeId);
    }

    /*
     unfollow
     --------
     followerId stops following followeeId
     */
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
