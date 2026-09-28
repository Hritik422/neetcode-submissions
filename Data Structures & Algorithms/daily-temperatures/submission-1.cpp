class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n=temperatures.size(),i;
        vector<int>ans(n);
        ans[n-1]=0;
        for(i=n-2;i>=0;i--){
            if(temperatures[i]<temperatures[i+1])ans[i] = 1 ;
            else{
                int j=ans[i+1]+i;
                while(j<n){
                    if(temperatures[j]>temperatures[i]){
                        ans[i] = j-i;
                        break;
                    }else if(ans[j]==0){
                        ans[i]=0;
                        break;
                    }
                    j+=ans[j];
                }
            } 
        }
        return ans;
    }
};
