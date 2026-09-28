class Solution {
public:
    bool isAlpha(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') ;
    }
    bool isPalindrome(string s) {
        string temp;
        for(int i=0;i<s.size();i++){
            if(isAlpha(s[i]))temp+=tolower(s[i]);
        }
        int i=0, j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
};
