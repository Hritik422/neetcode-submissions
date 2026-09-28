class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        for(int i=0;i<k;i++)q.push({nums[i],i});
        int i=0, j=k-1;
        while(j<nums.size()){
            while(q.top().second<i)q.pop();
            ans.push_back(q.top().first);
            i++;
            j++;
            q.push({nums[j],j});
        }
        return ans;
    }
};
