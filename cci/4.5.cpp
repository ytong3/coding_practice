/*
Write an algorithm to find the ‘next’ node (e.g., in-order successor) of a given node in
a binary search tree where each node has a link to its parent.
*/

#include <iostream>
#include "treenode.h"

using namespace std;
TreeNode* leftmost_node(TreeNode*);

TreeNode* find_next(TreeNode* node){
	//return the next
	if(node==NULL) return NULL;
	TreeNode* next_node;
	
	//case A: node has a right subtree. Then its successor is the leftmost child of the subtree.
	if(node->right!=NULL){
		return leftmost_node(node->right);
	}else{//case B: the node has no right subtree
	//case B.1: the node is the left child of its parent and has no right child
		if(node->parent==NULL)//special case that node is the root
			return NULL;
		if(node==node->parent->left){//return its parent since it has no right child. However, be careful the node may be the root node.
		return node->parent;
		}
	//case B.2: the node is the right child of its parent or the root node and has no right child.
		if(node==node->parent->right){//find the parent of the subtree the node concludes.
			next_node=node;
			//trace back
			while(next_node!=next_node->parent->left){
				if(node->parent==NULL) return NULL;//special case that node is the root.
				next_node=next_node->parent;
				}
			return next_node->parent;
		}
		return NULL;
	}
}

TreeNode* leftmost_node(TreeNode* node){
	if(node==NULL) return NULL;
	while(node->left!=NULL){
		node=node->left;
	}

	return node;
}
