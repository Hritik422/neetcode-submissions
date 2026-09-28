class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size()-1, n=matrix[0].size();
        while(low<high){
            int mid = (low+high)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]>target)high=mid-1;
            else low = mid+1;
        }
        int low2 = 0 , high2 = n-1;
        if(high<0)high++;
        if(matrix[low][0]==target || matrix[high][0]==target)return true;
        else if(matrix[low][0]>target)low--;
        while(low>=0 && low2<=high2){
            int mid = (low2+high2)/2;
            if(matrix[low][mid]==target)return true;
            else if(matrix[low][mid]>target)high2=mid-1;
            else low2 = mid+1;
        }
        return false;
    }
};
