class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(auto it:s){
            if((it>='a' && it<='z') || (it>='A' && it<='Z') || (it>='0' && it<='9'))temp+= tolower(it);
        }
        int i=0, j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]){return false;}
            i++;
            j--;
        }
        return true;
    }
};
