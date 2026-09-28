class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i, n=strs.size();
        map<vector<int>,vector<string>>mp;
        for(i=0;i<n;i++){
            vector<int> temp(26, 0);
            for(int j=0;j<strs[i].size();j++){
                temp[strs[i][j]-'a']++;
            }
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>>ans;

        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
