class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1, ans=0;
        while(i<j){
            int area = (j-i)*(min(heights[i], heights[j]));
            if(heights[i]<heights[j])i++;
            else j--;
            ans=max(ans, area);
        }
        return ans;
    }
};
