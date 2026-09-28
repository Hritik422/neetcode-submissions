class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int i=0, j=0, n=s.size(), ans=0;
        while(j<n){
           if(mp[s[j]]>0){
              while(i<n && mp[s[j]]>0){
                mp[s[i]]--;
                i++;
              }
           }
            mp[s[j]]++;
           j++;
           ans=max(ans, j-i);
        }
        return ans;
    }
};
