//Node the index. especially, the index of end element given the index of the start.
//if the index of the start is n1, the length of the array is n, then the index of the last element is n1+n-1!

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.clear();
        if(matrix.size()==0)
            return res;
        soHelper(matrix, matrix.size(),matrix[0].size(),res);
        return res;
    }
    
    void soHelper(vector<vector<int> >matrix, int height, int length, vector<int> &res){
        int x=(matrix[0].size()-length)/2;
        int y=(matrix.size()-height)/2;
        if(height==0||length==0) return;
        
        if(height==1){
            for(int idx=x;idx<length+x;idx++){
                res.push_back(matrix[y][idx]);
            }
            return;
        }
        
        if(length==1){
            for(int idx=y;idx<=y+height-1;idx++){
                res.push_back(matrix[idx][x]);
            }
            return;
        }
        
        for(int idx=x;idx<x+length;idx++){
            res.push_back(matrix[y][idx]);
        }
        
        for(int idx=y+1;idx<y+height;idx++){
            res.push_back(matrix[idx][x+length-1]);
        }
        
        for(int idx=x+length-2;idx>=x;idx--){
            res.push_back(matrix[y+height-1][idx]);
        }
        
        for(int idx=y+height-2;idx>=y+1;idx--){
            res.push_back(matrix[idx][x]);
        }
        
        soHelper(matrix,height-2,length-2,res);
    }
};