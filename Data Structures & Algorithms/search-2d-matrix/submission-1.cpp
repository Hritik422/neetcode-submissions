class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size(), i=0, j=n-1;
        while(i<j){
            int mid= (i+j)/2;
            if(matrix[mid][m-1]>target){
                j=mid;
            }else if(matrix[mid][m-1]<target){
                i=mid;
            }else return true;

            if(i+1==j || i==j){
                if(matrix[i][m-1]==target || matrix[j][m-1]==target)return true;
                else break;
            }
        }
        // cout<<i<<" "<<j<<endl;
        // cout<<target<<" "<<matrix[i][m-1]<<endl;
        int row=target>matrix[i][m-1]?j:i;
        i=0;j=m-1;
        cout<<row<<endl;
        while(i<=j){
            int mid=(i+j)/2;
            if(matrix[row][mid]<target)i=mid+1;
            else if(matrix[row][mid]>target)j=mid-1;
            else return true;
        }
        return false;
    }
};
