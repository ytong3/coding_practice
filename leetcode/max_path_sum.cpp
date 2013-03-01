#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;
//Definition for binary tree
  struct TreeNode {
      int val;
 	  TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int result;
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        result=INT_MIN;
        maxPathHelper(root);
        return result;
    }
    
    int maxPathHelper(TreeNode *root){
        if(!root) return 0;
		printf("Node #%d,\n", root->val);
        int left_max = maxPathHelper(root->left);
        int right_max = maxPathHelper(root->right);
		printf("%d, %d\n",left_max,right_max);
        int csum=max(root->val,max(root->val+left_max,root->val+right_max));
        result = max(result,max(csum,root->val+left_max+right_max));
		printf("max path including current node:%d, global max:%d\n",csum, result);
		return csum;
    }
};

int main(){
	TreeNode* root=new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	Solution mySol;
	mySol.maxPathSum(root);
	cout<<"Result="<<mySol.result<<endl;
}
	
