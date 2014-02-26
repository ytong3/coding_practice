class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
        if (n==0)
            return res;
        res[0]=INT_MAX;
        res[1]=INT_MIN;
        recur_helper(A,0,n,target,res);
        if (res[0]==INT_MAX){
            res[0]=-1;
            res[1]=-1;
        }
        return res;
    }
    void recur_helper(int A[], int start, int end, int target, vector<int> &res)
    {
        if (start>=end){
            return;
        }
        int mid=start+(end-start)/2;
        if (A[mid]<=target)
            recur_helper(A,mid+1,end,target,res);
        if (A[mid]>=target)
            recur_helper(A,start,mid,target,res);
        if (A[mid]==target){
            res[0]=res[0]>mid?mid:res[0];
            res[1]=res[1]<mid?mid:res[1];
        }
    }
};