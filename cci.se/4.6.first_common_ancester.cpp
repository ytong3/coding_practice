#include <iostream>
#include <string>
#include <vector>
#include "treenode.h"

using namespace std;

TreeNode* first_common_ancestor(TreeNode *root, TreeNode *r1, TreeNode *r2) {
	//root is the first ancestor of either r1 or r2.
	if (!root) return NULL;
	if (root->left==r1||root->right==r1||root->left==r2||root->right==r2)
		return root;
	
	TreeNode *l = first_common_ancestor(root->left,r1,r2);
	TreeNode *r = first_common_ancestor(root->right,r1,r2);

	if(l&&r) return root;
	if(l) return l;
	return r;
}




