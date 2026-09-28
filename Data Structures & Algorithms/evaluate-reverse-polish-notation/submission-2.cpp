class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        st.push(tokens[0]);
        int i=1;
        while(i<tokens.size() && !st.empty()){
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="/" || tokens[i]=="-"){
               int top = stoi(st.top());
               st.pop();
               int topSecond = stoi(st.top());
               st.pop();
               if(tokens[i]=="+"){
                st.push(to_string(top+topSecond));
               }else if(tokens[i]=="-"){
                st.push(to_string(topSecond-top));
               }else if(tokens[i]=="*"){
                st.push(to_string(topSecond*top));
               }else{
                st.push(to_string(topSecond/top));
               }
            }else{
                st.push(tokens[i]);
            }
            i++;
        }
        return stoi(st.top());
    }
};
