class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),i;
        vector<int>ans(n);
        vector<int>prev(n,1), next(n,1);
        prev[0]=nums[0];
        for(i=1;i<n;i++){
            prev[i]=nums[i]*prev[i-1];
        }
        next[n-1]=nums[n-1];
        for(i=n-2;i>=0;i--){
            next[i]=nums[i]*next[i+1];
        }
        for(i=0;i<n;i++){
            if(i==0)ans[i]=next[i+1];
            else if(i==n-1)ans[i]=prev[i-1];
            else ans[i]=prev[i-1]*next[i+1];
        }
        return ans;
    }
};
