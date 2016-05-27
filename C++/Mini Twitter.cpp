/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */

class MiniTwitter {
    
public:
    MiniTwitter() :time_(0) {}
    
    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        const Tweet &t = Tweet::create( user_id, tweet_text);
        userTimeline[ user_id ].push_back( make_pair(++time_, t) );
        return t;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        userFollowingUsers[ user_id ].insert( user_id );
        
        using revIt = std::vector<pair<uint,Tweet>>::reverse_iterator;
        priority_queue<tuple<uint, revIt, revIt>> maxHeap;
        
        
        for( int id : userFollowingUsers[ user_id ]) {
            auto &news = userTimeline[ id ];
            
            if( news.size() ) {
                maxHeap.push( make_tuple(news.rbegin()->first,
                                         news.rbegin(),
                                         news.rend()
                                         ) );
            }
        }
        
        vector<Tweet> recentTweets;
        while( recentTweets.size() < numberOfRecentTweets && !maxHeap.empty() ){
            const auto& top = maxHeap.top();

            uint currTime;
            revIt begin, end;
            std::tie( currTime, begin, end) = top;
            maxHeap.pop();
            
            revIt next = begin+1;
            if(next != end) {
                maxHeap.push( make_tuple( next->first, next, end) );
            }
            
            recentTweets.push_back( begin->second );
        }
        return recentTweets;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        vector<Tweet> recentTweets;
    
        const auto& timeline = userTimeline[ user_id ];
        for(auto it = timeline.rbegin(); recentTweets.size() < numberOfRecentTweets &&
            it != timeline.rend(); ++it){
                recentTweets.push_back( it->second );
        }
        return recentTweets;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        userFollowingUsers[ from_user_id ].insert( to_user_id );
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        userFollowingUsers[ from_user_id ].erase( to_user_id );
    }
    
private:
    const uint numberOfRecentTweets = 10;
    unordered_map<int, set<int>> userFollowingUsers;
    unordered_map<int, vector<pair<uint, Tweet>>> userTimeline;
    uint time_;
    
};