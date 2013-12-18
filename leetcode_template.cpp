#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;

 /**  
  * Definition for binary tree  
  * struct TreeNode {  
  *   int val;  
  *   TreeNode *left;  
  *   TreeNode *right;  
  *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
  * };  
  */  
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

int main(){
	Solution mysol;
    vector<int> res=mysol.getRow(4);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
		
