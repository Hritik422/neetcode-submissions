class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        vector<vector<int>>temp(nums.size()+1);
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            temp[it.second].push_back(it.first);
        }
        for(int i=nums.size();i>=0 && k>0;i--){
            if(temp[i].size()>0){
                for(auto it:temp[i])ans.push_back(it);
                k-=temp[i].size();
            }
        }
        return ans;
    }
};
