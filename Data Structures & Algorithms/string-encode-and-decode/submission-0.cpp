class Solution {
public:
    map<string, vector<string>>mp;
    string encode(vector<string>& strs) {
        string res;
        for(auto it:strs)res+=it;
        mp[res] = strs;
        return res;
    }

    vector<string> decode(string s) {
       return mp[s];
    }
};
