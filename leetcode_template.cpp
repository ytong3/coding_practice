#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

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
	void flatten(TreeNode *root) {
		preOrder(root,NULL);
		return;
	}
	
	TreeNode *preOrder(TreeNode *root, TreeNode *previous){
		if(root==NULL)//a NULL node do not have a previous node
			return NULL;
			
		TreeNode *left = root->left;
		TreeNode *right = root->right;
		
		if (previous == NULL){
			previous = root;
		}else{
			previous->left=NULL;
			previous->right=root;
			previous = root;//by this end, we finished processing current node and move forward.
		}
		
		if(left){
			previous = preOrder(left, previous);
		}
		if(right){
			previous = preOrder(right, previous);
		}
		
		return previous;
	}
	
};

int main(){
	Solution mysol;
	

}
		
