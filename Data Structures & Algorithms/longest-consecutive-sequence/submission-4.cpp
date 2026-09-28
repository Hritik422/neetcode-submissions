class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        int ans=0, maxi=INT_MIN;
        for(auto it:nums){mp.insert(it);maxi=max(maxi,it);}
        for(auto it:mp){
            int cnt=0;
            if(mp.find(it-1)==mp.end()){
            for(int i=it;i<=maxi;i++){
                if(mp.find(i)!=mp.end())cnt++;
                else break;
            }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
