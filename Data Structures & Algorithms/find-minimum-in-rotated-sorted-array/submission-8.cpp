class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, h=nums.size();
        while(l<h){
            int m = (l+h)/2;
            if(nums[m]>nums[l])l=m;
            else h=m;
        }
        if(h==nums.size()-1)h=-1;
        return nums[h+1];
    }
};
