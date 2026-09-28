class TimeMap {
public:
map<string, vector<pair<int,string>>>mp;
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>v = mp[key];
        int l=0, h= v.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(v[m].first==timestamp)return v[m].second;
            else if(v[m].first>timestamp)h = m-1;
            else l=m+1;
        }
        if (h >= 0)return v[h].second;
        else return "";
    }
};
