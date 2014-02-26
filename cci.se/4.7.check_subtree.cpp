//be aware of the solution that using suffix tree.
#include <iostream>
#include <string>
#include <vector>
#include "treenode.h"

using namespace std;

bool treeTree(TreeNode *t1, TreeNode *t2){
	//find a node that has the same value with t2's.
	 if(!t2) return true;
	 if(!t1) return false;
	 if(t1->val==t2->val)
	 	if (tree_match(t1,t2)) return true;
	return treeTree(t1->left,t2)||treeTree(t1->right,t2);
}
	 	
		

bool tree_match(TreeNode *t1, TreeNode *t2) {
	if (t2==NULL) return true;
	if (t1==NULL) return false;
	if (t1->val!=t2->val) return false;
	return tree_match(t1->left,t2->left)&&tree_match(t1->right,t2->right);
}

