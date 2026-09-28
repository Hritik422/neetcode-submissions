class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>v;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            vector<int>map(26,0);
            for(auto it:strs[i])map[it-'a']++;
            string key;
            for(int j=0;j<26;j++){
                key+= ':'+to_string(map[j]);
            }
            v[key].push_back(strs[i]);
        }
        for(auto it:v){
            ans.push_back(it.second);
        }
        return ans;
    }
};
