class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        //Definitely gotta know which rows and columns to clear before modifying the matrix.
        //Where to store this information is the key to the solution
        //we use the first column and first row so no extra space is needed
        int row=matrix.size();
        int col=matrix[0].size();
        bool clearRow=false;
        bool clearCol=false;
        for(int r=0;r<row;r++)
            if(matrix[r][0]==0){
                clearCol=true;
                break;
            }
            
        for(int c=0;c<col;c++)
            if(matrix[0][c]==0){
                clearRow=true;
                break;
            }
            
        
        for(int r=1;r<row;r++)
            for(int c=1;c<col;c++){
                if (matrix[r][c]==0){
                    matrix[0][c]=0;
                    matrix[r][0]=0;
                }
            }
        
        for(int r=1;r<row;r++){
            if(matrix[r][0]==0){
                for(int c=1;c<col;c++)
                    matrix[r][c]=0;
            }
        }
        
        for(int c=1;c<col;c++){
            if(matrix[0][c]==0){
                for(int r=1;r<row;r++)
                    matrix[r][c]=0;
            }
        }
        
        if(clearRow)
            for(int c=0;c<col;c++)
                matrix[0][c]=0;
        if(clearCol)
            for(int r=0;r<row;r++) 
                matrix[r][0]=0;
    }
};