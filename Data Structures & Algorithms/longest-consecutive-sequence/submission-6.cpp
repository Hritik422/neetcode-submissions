class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0,n=nums.size(),prev=INT_MIN,temp=0;
        if(n==0)return 0;
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp){
           if(it.first==prev+1){
            temp++;
           }
           else{
            ans=max(ans,temp);
            temp=0;
           }
           prev=it.first;
        }
        return max(temp,ans)+1;
    }
};
