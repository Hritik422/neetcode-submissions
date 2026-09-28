class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int total = len1 + len2;
        int half = (total+1)/2;
        vector<int>& A =nums1;
        vector<int>& B = nums2;
        if(len2<len1)swap(A,B);

        int l=0, r=min(len1, len2);
        while(l<=r){
            int mid = (l+r)/2;
            int other = half - mid ;

            int aLeft = mid>0 ? A[mid-1] : INT_MIN;
            int aRight = mid<A.size() ? A[mid] : INT_MAX;
            int bLeft = other>0 ? B[other-1] : INT_MIN;
            int bRight = other<B.size() ? B[other] : INT_MAX;

            if(aLeft<=bRight && bLeft<=aRight){
                if(total%2)return max(aLeft, bLeft);
                else return (max(aLeft, bLeft)+min(aRight, bRight))/2.0;
            }
            else if(aLeft>bRight)r=mid-1;
            else l = mid+1;
        }
        return -1;
    }
};