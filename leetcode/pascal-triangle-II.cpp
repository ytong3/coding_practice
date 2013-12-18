class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        vector<int> buffer(rowIndex+1,0);
        int row(0);
        while(row<=rowIndex){
            buffer=result;
            int colIndex(0);
            while(colIndex<row+1){
                if(colIndex==row||colIndex==0)
                    result[colIndex]=1;
                else{
                    result[colIndex]=buffer[colIndex]+buffer[colIndex-1];
                }
                colIndex++;
            }
            row++;
        }
        return result;
    }
};

//another very elegant solution using only one array.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        for(int i=0;i<rowIndex+1;i++){
            for(int j=i-1;j>0;j--){
                result[j]=result[j]+result[j-1];
            }
            result[i]=1;
        }
        return result;
    }
};
