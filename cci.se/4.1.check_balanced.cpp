#include <iostream>
#include <stdlib.h>
#include <climits.h>
#include <string>
#include <vector>
#include "treenode.h"

using namespace std;

//the solution below is over-complicated and wrong. Note that the definition of a balanced tree does not say the depth only applies to leaf node and it should not in this case.
int min_depth(TreeNode* root){
	if (!root) return 0;
	if (!root->left&&!root->right)
		return 1;
	
	int l=INT_MAX,r=INT_MIN;
	if (root->left) l=min_depth(root->left);
	if (root->left) r=min_depth(root->right);

	return 1+min(l,r);
}

int max_depth(TreeNode* root){
	if (!root) return 0;
	if (!root->left&&!root->right)
		return 1;
	int l=INT_MIN, r=INT_MIN;
	if (root->left) l = max_depth(root->left);
	if (root->right) r= max_depth(root->right);
	return 1+max(l,r);
}

bool check_balance(TreeNode *root){
	return max_depth(root)-min_depth(root)<=1;
}
	
