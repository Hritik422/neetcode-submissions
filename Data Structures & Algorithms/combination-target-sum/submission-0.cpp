class Solution {
public:
    void findSum(vector<int>& nums, int& target, int i, vector<vector<int>>& ans, vector<int>temp, int sum){
        if(i<0){
            return;
        }
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum+nums[i]<=target){
            temp.push_back(nums[i]);
            sum+=nums[i];
            findSum(nums, target,i,ans,temp, sum);
            temp.pop_back();
            sum-=nums[i];
            findSum(nums, target,i-1,ans,temp, sum);
        }else findSum(nums, target,i-1,ans,temp, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        findSum(nums, target, n-1, ans,{}, 0);
        return ans;
    }
};
