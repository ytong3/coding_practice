class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(m==0||n==0)
            return 0;
            
        if(m==1||n==1)
            return 1;
        
        vector<vector<int> > A;
        vector<int> tmp(n,0);
        A.resize(m,tmp);
        
        for(int i=0;i<n;i++){
            A[m-1][i]=1;
        }
        for(int i=0;i<m;i++){
            A[i][n-1]=1;
        }
        for(int row=m-2;row>=0;row--){
            for(int col=n-2;col>=0;col--){
                A[row][col]=A[row+1][col]+A[row][col+1];
            }
        }
        return A[0][0];
    }
};
