class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), ans=0, i;
        vector<int>v(n);
        v[n-1]=prices[n-1];
        for(i=n-2;i>=0;i--){
            v[i]=max(v[i+1], prices[i]);
        }
        for(i=0;i<n;i++){
            ans=max(ans, v[i]-prices[i]);
        }
        return ans;
    }
};
