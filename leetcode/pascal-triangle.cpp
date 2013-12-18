class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows==0)
            return result;
        vector<int> tempRow(1,1);
        result.push_back(tempRow);
        int row(1);
        while(row<numRows){
            vector<int> rowVec;
            for(int i=0;i<result[row-1].size()+1;i++){
                if(i==0||i==result[row-1].size()) rowVec.push_back(1);
                else rowVec.push_back(result[row-1][i-1]+result[row-1][i]);
            }
            result.push_back(rowVec);
            row++;
        }
        return result;
    }
};