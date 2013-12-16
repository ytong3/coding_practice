class Solution {
public:
    double pow(double x, int n) {
        //n can be very large.
        //if trying to multiply x n times, the complexity is O(n).
        //however, we can use recursion, and prevent doing duplicate work.
        if(n==0)
            return 1.0;
        //if(n==-1)
        //    return 1.0/x;
        double half = pow(x,n/2);
        if(n%2==0){
            return half*half;
        }
        else{
            if(n>0)
                return half*half*x;
            else
                return half*half/x;
        }
    }
};