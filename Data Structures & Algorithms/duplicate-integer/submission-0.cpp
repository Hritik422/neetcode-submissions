class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,bool>mp;
        for(auto it:nums){
            if(mp.find(it)!=mp.end())return true;
            mp[it]=true;
        }
        return false;
    }
};
