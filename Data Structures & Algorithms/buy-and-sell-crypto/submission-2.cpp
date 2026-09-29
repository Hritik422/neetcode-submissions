class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, n=prices.size(), ans=0;
        vector<int>maxi(n,0);
        maxi[n-1] = prices[n-1];
        for(i=n-2;i>=0;i--){
            maxi[i] = max(prices[i], maxi[i+1]);
        }
        for(i=0;i<n-1;i++){
            ans = max(ans, -prices[i]+maxi[i+1]);
        }
        return ans;
    }
};
