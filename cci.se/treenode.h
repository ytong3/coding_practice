#include "stdio.h"

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode *parent;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//function to traverse the tree

void preorder_traverse(TreeNode* root){
	if(root==NULL) return;

	printf("NODE %d\n", root->val);
	preorder_traverse(root->left);
	preorder_traverse(root->right);
}
