class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int nrow=obstacleGrid.size();
        int ncol=obstacleGrid[0].size();
        
        if(nrow==0||ncol==0)
            return 0;
        
        if(nrow==1){
            for(int i=0;i<ncol;i++){
                if(obstacleGrid[0][i]==1){
                    return 0;
                }
            }
            return 1;
        }
        
        if(ncol==1){
            for(int row=0;row<nrow;row++){
                if(obstacleGrid[row][0]==1){
                    return 0;
                }
            }
            return 1;
        }
        
        if(obstacleGrid[nrow-1][ncol-1]==1||obstacleGrid[0][0]==1)
            return 0;
        
        vector<int> temp(ncol,-1);
        vector<vector<int> > A(nrow,temp);
        A[nrow-1][ncol-1]=1;
        
        for(int row=nrow-2;row>=0;row--){
            if(obstacleGrid[row][ncol-1]==1){
                A[row][ncol-1]=0;
            }else if(A[row+1][ncol-1]==0){
                A[row][ncol-1]=0;
            }else
                A[row][ncol-1]=1;
        }
        
        for(int col=ncol-2;col>=0;col--){
            if(obstacleGrid[nrow-1][col]==1)
                A[nrow-1][col]=0;
            else if(A[nrow-1][col+1]==0){
                A[nrow-1][col]=0;
            }else
                A[nrow-1][col]=1;
        }
        
        for(int row=nrow-2;row>=0;row--){
            for(int col=ncol-2;col>=0;col--){
                if(obstacleGrid[row][col]==1){
                    A[row][col]=0;
                }else
                    A[row][col]=A[row+1][col]+A[row][col+1];
            }
        }
        
        return A[0][0];
        
    }
};
