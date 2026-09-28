class Solution {
public:
    int characterReplacement(string s, int k) {
        int curMax = 0, i = 0, n = s.size(), j = 0, ans=0;
        unordered_map<char,int> mp;
        while(j < n){
           mp[s[j]]++;
           if(mp[s[j]] > curMax){
            curMax = mp[s[j]];
           }
           if(curMax + k >= (j-i+1)){
            ans = max(ans , j-i+1);
           }else{
            while(curMax + k < (j-i+1)){
                mp[s[i]]--;
                for(auto it:mp)curMax=max(it.second, curMax);
                i++;
            }
           }
           j++;
        }
        return ans;

    }
};
