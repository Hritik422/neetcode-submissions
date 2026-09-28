class Twitter {
private:
  vector<pair<int,int>>v;
  int mp[101][101] = {0};
  
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       v.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int atMost = 10;
        vector<int>ans;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i].first==userId || mp[userId][v[i].first]==1){
                ans.push_back(v[i].second);
                atMost--;
                if(atMost==0)break;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
         mp[followerId][followeeId]=0;
    }
};
