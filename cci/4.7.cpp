//ideas. First find a node in the big tree that has the same value as that of the root of the small tree. Then check if the two are the same tree.
//The idea is pretty intuitive.


#include <iostream>
#include "treenode.h"

using namespace std;
int subTree(TreeNode*, TreeNode*);
int matchTree(TreeNode*,TreeNode*);

//wrapper function
int containsTree(TreeNode *r1, TreeNode* r2){
	if(!r2) return 1;//an empty tree is always a subtree
	return subTree(r1,r2);
}

int subTree(TreeNode *r1, TreeNode *r2){
	if(r1==NULL) return 0;
	
	if(r1->val==r2->val){//it is promising, but only possibile
		if(matchTree(r1,r2)) return 1;
		}
	
	//continue finding new condidate subtree for inspection.
	return subTree(r1->left,r2)||subTree(r1->right,r2);
}

int matchTree(TreeNode* r1, TreeNode* r2){
	if(r1==NULL&&r2==NULL) return 1;
	if(r1&&r2) return 0;
	if(r1->val!=r2->val) return 0;
	return matchTree(r1->left,r2->left)&&matchTree(r1->right,r2->right);
}
	
