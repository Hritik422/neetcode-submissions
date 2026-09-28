class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            map<char,int>mp;
            for(auto it:board[i])if(it!='.')mp[it]++;
            for(auto it:mp){
                if(it.first<'1' || it.first>'9' || it.second>1){
                    cout<<it.first<<" "<<it.second<<" "<<i;
                    return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            map<char,int>mp;
            for(int j=0;j<9;j++)if(board[j][i]!='.')mp[board[j][i]]++;
            for(auto it:mp){
                if(it.first<'1' || it.first>'9' || it.second>1)return false;
            }
        }
        for(int i=0;i<9;i++){
            int col = ((i%3)*3);
            int row = i%3;
            map<char,int>mp;

            for(int k=row;k<row+3;k++){
                for(int j=col;j<col+3;j++)if(board[k][j]!='.')mp[board[k][j]]++;
            }
             for(auto it:mp){
                if(it.first<'1' || it.first>'9' || it.second>1){
                    return false;
                }
            }
        }
        return true;
    }
};
