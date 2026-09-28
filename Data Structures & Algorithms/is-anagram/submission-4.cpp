class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp,mp1;
        for(auto it:s)mp[it]++;
        for(auto it:t)mp1[it]++;
        for(auto it:mp){
            if(it.second!=mp1[it.first])return false;
        }
        for(auto it:mp1){
            if(it.second!=mp[it.first])return false;
        }
        return true;
    }
};
