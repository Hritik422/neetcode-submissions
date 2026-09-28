class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size();
        while(l<h){
            int m = (l+h)/2;
            if(nums[m]>nums[l])l=m;
            else h=m;
        }
        if(h==nums.size()-1)h=-1;
        int low, high;
        if(target>=nums[h+1] && target<=nums[nums.size()-1]){
            low=h+1, high=nums.size()-1;
        }else{
            low=0, high=h+1;
        }
        while(low<=high){
            int m = (low+high)/2;
            if(nums[m]==target)return m;
            else if(target>nums[m])low=m+1;
            else high=m-1;
        }
        return -1;
    }
};
