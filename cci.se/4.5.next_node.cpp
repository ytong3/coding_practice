#include <iostream>
#include <string>
#include <vector>
#include "treenode.h"
//#include "4.4.minimal_height_tree.cpp"

using namespace std;
TreeNode *m_height_tree(vector<int>&,int,int);
TreeNode *find_next(TreeNode *root) {
	//if root is null
	if(!root) return NULL;
	
	//if root is has a right child, next node is the leftmost node of the subtree	
	if (root->right!=NULL) {
		//find the left most element
		TreeNode *p = root->right;
		while (p->left)
			p=p->left;
		return p;
	}

	TreeNode *par = root->parent;
	//if root is the left child of parent;
	if (par==NULL||root == par->left) return par;
	//if root is the right child of parent; it means we have done traversing the left subtree rooted such that the subtree's rightmost node is root. now find the root of the big subtree.	
	while (par){//par has the potential to become NULL. Ensure it will not in the loop body
		if (par->left==root) return par;
		root = par;
		par = root->parent;
	}
	return NULL;
}
	
int main() {
	vector<int> arr;
	for (int i=0;i<10;i++)
		arr.push_back(i);
	

	TreeNode *root = m_height_tree(arr,0,arr.size()-1);
	root->level_traverse();
	TreeNode *p=find_next(root->left->left);
	if(p) cout<<p->val<<endl;
	else cout<<"NULL"<<endl;

}
	
	
