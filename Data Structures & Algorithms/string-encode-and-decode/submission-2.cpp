class Solution {
public:

    string encode(vector<string>& strs) {
        string temp;
         for(auto it:strs)temp+=to_string(it.size())+'#'+it;
         return temp;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        for(int i=0;i<s.size();i++){
            int length=0;
            while(s[i]!='#'){
               length = length*10 + int(s[i]-'0');
               i++;
            }
            i++;
            int cur = i;
            string res;
            while(i<length+cur){
               res+=s[i];
               i++;
            }
            ans.push_back(res);
            if(i>=s.size())break;
            i--;
        }
        return ans;
    }
};
