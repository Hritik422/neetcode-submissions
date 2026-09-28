class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m,mp1;
        for(auto it:s)mp1[it]++;
        for(auto it:t)m[it]++;
        if(mp1.size()!=m.size())return false;
        for(auto it:mp1){
            if(it.second!=m[it.first])return false;
        }
        return true;
    }
};
