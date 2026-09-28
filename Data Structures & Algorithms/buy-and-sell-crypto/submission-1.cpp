class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j=prices.size(), maxi=0, ans=0;
        --j;
        while(j>=0){
            maxi=max(maxi, prices[j]);
            ans = max(ans, maxi-prices[j]);
            j--;
        }
        return ans;
    }
};
