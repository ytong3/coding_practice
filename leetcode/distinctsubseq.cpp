#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
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
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //two-dimensional DP
        int len1=S.length();
        int len2=T.length();
        if(len2==0||len1==0)
            return 0;
        if(len1<len2)
            return 0;
        
        vector<int> temp(len2+1,0);
        vector<vector<int> > A(len1+1,temp);
        
        for(int row=0;row<=len1;row++){
            A[row][0]=0;
        }
        for(int col=0;col<=len2;col++){
            A[0][col]=1;
        }
        
        for(int row=1;row<=len1;row++){
            for(int col=1;col<=len2;col++){
                if(row<col)
                    A[row][col]=0;
                else if (S[row-1]==T[col-1])
                    A[row][col]=(col==1?1:A[row-1][col-1])+A[row-1][col];
                else
                    A[row][col]=A[row-1][col];
                cout<<A[row][col]<<" ";
            }
            cout<<endl;
        }
        
        return A[len1][len2];
    }
};

int main(){
	Solution mysol;
	string str1("aabb");
	string str2("abb");
	
	cout<<mysol.numDistinct(str1,str2);

}
		
