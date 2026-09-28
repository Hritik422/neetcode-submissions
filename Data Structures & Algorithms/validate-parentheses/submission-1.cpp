class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')st.push(s[i]);
            else{
                if(st.size()==0)return false;
                char top = st.top();
                if((top=='{' && s[i]!='}') || (top=='[' && s[i]!=']') || (top=='(' && s[i]!=')'))return false;
                st.pop();
            }
        }
        if(st.size()>0)return false;
        return true;
    }
};
