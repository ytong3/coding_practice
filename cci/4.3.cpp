//Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.


#include <iostream>
#include <vector>
#include "treenode.h"
using namespace std;

TreeNode* add_to_tree(vector<int> array, int idx1, int idx2){
	//input error checking
	if(array.size()==0) return NULL;
	if(idx1>idx2) return NULL;

	//find the middle element (note it is a sorted array)
	int mid=(idx1+idx2)/2;
	TreeNode *root=new TreeNode(array[mid]);
	root->left=add_to_tree(array, idx1, mid-1);
	root->right=add_to_tree(array, mid+1, idx2);

	return root;
}

/*	
int main(){
	vector<int> arr;
	arr.clear();

	for(int i=0;i<10;i++)
		arr.push_back(i);

	TreeNode* root=add_to_tree(arr, 0, arr.size()-1);
	
	preorder_traverse(root);
}
*/
