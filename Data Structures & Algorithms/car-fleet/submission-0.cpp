class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int ans=1, i;
        for(i=0;i<speed.size();i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        double base=double(target-v[0].first)/v[0].second;
        for(i=0;i<v.size();i++){
            double cur = double(target-v[i].first)/v[i].second;
            if(cur<=base)continue;
            else{
                ans++;
                base=cur;
            }
        }
        return ans;
    }
};
