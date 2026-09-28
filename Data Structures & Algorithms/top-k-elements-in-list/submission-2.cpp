class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        vector<vector<int>>frequency(n+1);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            frequency[it.second].push_back(it.first);
        }

        for(int i=n;i>=0;i--){
           for(int j=0;j<frequency[i].size();j++){
              ans.push_back(frequency[i][j]);
              --k;
              if(k==0)return ans;
           }
        }
        return ans;

    }
};
