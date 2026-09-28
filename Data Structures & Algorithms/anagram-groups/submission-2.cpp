class Solution {
public:
   string myHash(string str) {
     vector<int> freq(26, 0);
     for (char c : str) {
         freq[c - 'a']++;
     }
     string hash = "";
     for (int x : freq) {
        hash += to_string(x) + "#";
     }
     return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto it:strs){
            mp[myHash(it)].push_back(it);
        }

        for(auto it:mp){
            vector<string> temp;
            for(auto it2:it.second){
                temp.push_back(it2);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};
