class Solution {
public:
    bool poss(vector<int>& v, int h, int m){
        int res=0;
        for(auto it:v){
            res+=it/m;
            if(it%m)++res;
        }
        return res<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int low = 1, high = 1e9;
        while(low<=high){
            int mid = (low+high)/2;
            if(poss(piles, h, mid))high=mid;
            else low=mid+1;
            if(low==high)break;
        }
        return high;
    }
};