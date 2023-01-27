class TweetCounts {
public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        tweets_[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = freq[0] == 'm' ? 60 : (freq[0] == 'h' ? 3600 : 86400);
        const auto& times = tweets_[tweetName];
        vector<int> result(((endTime - startTime) / interval) + 1);
        const auto& end = times.upper_bound(endTime);
        for (auto it = times.lower_bound(startTime); it != end; it++) {
           result[(it->first - startTime) / interval] += it->second;
        }
        return result;
    }
    
private:
    unordered_map<string, map<int, int>> tweets_;
};