//A similar approach to Stock III.
//The key observation is to divide the problem to subproblems of finding the water held in each bar! Divide and Conquer is really the way to go in many cases!

class Solution {
public:
    int trap(int A[], int n) {
        if (n<2) return 0;
        
        //get the highest bar on the left for each bar (inclusive)
        int left[n];
        int right[n];
        
        left[0]=A[0];
        for (int i=1;i<n;i++){
            left[i]=max(left[i-1],A[i]);
        }
        
        right[n-1]=A[n-1];
        for (int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],A[i]);
        }
        
        int res(0);
        for (int i=0;i<n;i++){
            res+=min(left[i],right[i])-A[i];
        }
        return res;
    }
};