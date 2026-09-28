class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        map<int, bool>mp;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]>0)break;
            int fixed = nums[i];
            int j=i+1, k=n-1;
            unordered_map<int, bool>mp1;
            while(j<k && !mp[fixed]){
                if(mp1[nums[j]]){
                    j++;
                    continue;
                }else if(mp1[nums[k]]){
                    k--;
                    continue;
                }
                if(nums[j]+nums[k]+fixed==0){
                    ans.push_back({nums[j], nums[k], fixed});
                     mp1[nums[j]]=true;
                    mp1[nums[k]]=true;
                    j++;
                    k--;
                }else if(nums[j]+nums[k]+fixed>0){
                    k--;
                }else{
                    j++;
                }
            }
            mp[fixed] = true;
        }
        return ans;
    }
};
