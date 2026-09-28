class Solution {
public:
    int trap(vector<int>& height) {
        int i=0, j=height.size()-1, ans=0, n=height.size();
        vector<int>postMax(n), preMax(n);
        postMax[n-1] = height[n-1];
        preMax[0] = height[0];
        for(int k=n-2;k>=0;k--){
           postMax[k] = max(height[k], postMax[k+1]);
        }
        for(int k=1;k<n;k++){
            preMax[k] = max(height[k], preMax[k-1]);
        }
        // while(i+1<height.size()){
        //     if(height[i]>height[i+1])break;
        //     ++i;
        // }
        // while(j-1>=0){
        //     if(height[j]>height[j-1])break;
        //     --j;
        // }
        int cur = height[i];
        while(i<j){
            int trapped = min(preMax[i], postMax[i])-height[i];
            if(trapped>0){
              ans+=trapped;
            }
           i++;
        }
        return ans;

    }
};
