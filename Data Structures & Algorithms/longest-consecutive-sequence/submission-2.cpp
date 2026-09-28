class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        int ans=0, maxi=INT_MIN, max_so_far=INT_MIN;
        for(auto it:nums){mp[it]++;maxi=max(maxi,it);}
        for(auto it:mp){
            int cnt=0;
            if(it.first>max_so_far){
            for(int i=it.first;i<=maxi;i++){
                if(mp[i]){
                cnt++;
                max_so_far=max(i, max_so_far);
                }
                else break;
            }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
