class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0, n = s.size(), ans = 0;
        while(j<n){
           if(mp[s[j]]==1){
             ans = max(ans, j-i);
             while(mp[s[j]]==1){
                mp[s[i]]--;
                i++;
             }
           }
           mp[s[j]]++;
           j++;
        }
        return max(ans, j-i);
    }
};
