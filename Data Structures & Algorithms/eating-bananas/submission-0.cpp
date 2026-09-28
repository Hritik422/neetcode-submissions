class Solution {
public:
    bool possible(vector<int>& v, int h, int m){
        for(int i=0;i<v.size();i++){
             h-= v[i]/m;
            if(v[i]%m)h--;
            if(h<0)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini=1, maxi=1e9, ans=1e9;
        while(mini<=maxi){
            int mid = (mini+maxi)/2;
            if(possible(piles, h, mid)){
                ans=min(ans,mid);
                maxi=mid-1;
            }else{
                mini=mid+1;
            }
        }
        return ans;
    }
};
