class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp,mp1;
        for(auto it: s1) mp[it]++;
        int i=0, j=s1.size()-1, n=s2.size();
        for(int k=i;k<=j;k++)mp1[s2[k]]++;
        j++;
        while(j<n){
            if(mp==mp1)return true;
            mp1[s2[i]]--;
            mp1[s2[j]]++;
            if(mp1[s2[i]]<=0)mp1.erase(s2[i]);
            i++;
            j++;
        }
        if(mp==mp1)return true;
        else return false;
    }
};
