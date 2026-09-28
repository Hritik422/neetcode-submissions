class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int i=0, j=0, n=s.size(), ans=0;
        while(j<n){
           if(mp[s[j]]>0){
            while(s[i]!=s[j]){mp[s[i]]--;i++;}
            mp[s[i]]--;
            i++;
           }
            ans=max(ans, j-i+1);
            mp[s[j]]++;
            ++j;
        }
        return ans;
    }
};
