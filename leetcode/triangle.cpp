class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row_num=triangle.size();
        for(row_num=triangle.size()-2;row_num>=0;row_num--){
            for(int element_num=0;element_num<triangle[row_num].size();element_num++){
                if(triangle[row_num+1][element_num]>triangle[row_num+1][element_num+1])
                    triangle[row_num][element_num]+=triangle[row_num+1][element_num+1];
                else
                    triangle[row_num][element_num]+=triangle[row_num+1][element_num];
            }
        }
        return triangle[0][0];
    }
};
