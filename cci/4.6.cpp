/*
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.
*/

#include <iostream>
#include "treenode.h"

//use recursion
int cover(TreeNode *node, TreeNode *n1, TreeNode *n2){
	//a preorder traversal
	//base case:q
	int res(0);
	if(node==NULL) return res;
	
	if(node==n1||node==n2) res++;
	res+=cover(node->left,n1,n2);

	if(res==2) return 2;//will save some computation.
	return res+cover(node->right,n1,n2);
}

//this function is also a recursion function. Pay special attention to that how the recursion shrinks the size of the problem.
//essnetially, this function returns the n1 and n2's common ancestor in the subtree rooted in 'node'. The invariance: the common ancestor, which is the same for the all the subtrees of the substree as long as the subtrees covers both the two nodes.
TreeNode *first_common_ancestor(TreeNode* node, TreeNode* n1, TreeNode* n2){
	//base case
	if(node==NULL) return NULL;

	if(n1==n2&&(
	if(node->left==n1&&node->right==n2) return node;


	int l_counter(0), r_counter(0);
	
	
	
