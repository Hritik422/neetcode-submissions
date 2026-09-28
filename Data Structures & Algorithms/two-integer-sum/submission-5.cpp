class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        while(i<j){
            if(v[i].first+v[j].first<target){
                i++;
            }else if(v[i].first+v[j].first>target){
                j--;
            }else{
              if(v[i].second<v[j].second) return {v[i].second, v[j].second};
              else return {v[j].second, v[i].second};
            }
        }
        return {};
    }
};
