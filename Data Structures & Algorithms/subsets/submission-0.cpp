class Solution {
public:
vector<vector<int>>ans;
    void findSub(vector<int>& nums, int i, vector<int> temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
            temp.push_back(nums[i]);
            findSub(nums, i+1, temp);
            temp.pop_back();
            findSub(nums, i+1, temp);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        findSub(nums, 0, temp);
        return ans;
    }
};
